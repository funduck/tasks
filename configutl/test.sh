#!/bin/bash
# It is BASH test script 

configutl="$@"

echo Part 1: no TEST_CONFIG_PROFILE
unset TEST_CONFIG_PROFILE
cases=("--file test_config.json --user maria --host laptop --getstd \"database.port database.user\""
"--file test_config.json --user maria --host test-01 --getstd \"database.port database.user\""
"--file test_config.json --user maria --host test-01 --profile unittesting --getstd \"database.port database.user\"")
results=("27017 'dbuser'"
"29017 'test_dbuser'"
"29017 ''")
for (( i=0; i<${#cases[@]}; i++ )); do
    res="`$configutl ${cases[$i]}`"
    if [ "$res" != "${results[$i]}" ]; then
        echo invalid case $i: "$res" != "${results[$i]}"
        unset TEST_CONFIG_PROFILE
        exit -1;
    fi
    echo -e "\033[32m case $i\033[m"
done

echo Part 2: with TEST_CONFIG_PROFILE
export TEST_CONFIG_PROFILE=unittesting
cases=("--file test_config.json --user maria --host laptop --getstd \"database.port database.user\""
"--file test_config.json --user maria --host test-02 --getstd \"database.port database.user\""
"--file test_config.json --user maria --host test-02 --profile \"\" --getstd \"database.port database.user\"")
results=("27017 'dbuser'"
"29017 ''"
"29017 'test_dbuser'")
for (( i=0; i<${#cases[@]}; i++ )); do
    res="`$configutl ${cases[$i]}`"
    if [ "$res" != "${results[$i]}" ]; then
        echo invalid case $i: "$res" != "${results[$i]}"
        unset TEST_CONFIG_PROFILE
        exit -1;
    fi
    echo -e "\033[32m case $i\033[m"
done

echo -e "\033[32mAll passed\033[m"
unset TEST_CONFIG_PROFILE