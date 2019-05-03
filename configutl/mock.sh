#!/bin/bash
case "$@" in
    "--file test_config.json --user maria --host laptop --getstd \"database.port database.user\"")
        echo "27017 'dbuser'"
        break
    ;;
    "--file test_config.json --user maria --host test-01 --getstd \"database.port database.user\"")
        echo "29017 'test_dbuser'"
        break
    ;;
    "--file test_config.json --user maria --host test-01 --profile unittesting --getstd \"database.port database.user\"")
        echo "29017 ''"
        break
    ;;
    "--file test_config.json --user maria --host test-02 --getstd \"database.port database.user\"")
        echo "29017 ''"
        break
    ;;
    "--file test_config.json --user maria --host test-02 --profile \"\" --getstd \"database.port database.user\"")
        echo "29017 'test_dbuser'"
        break
    ;;
    *)
        echo unexpected $@
    ;;
esac
