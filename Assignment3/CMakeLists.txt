cmake_minimum_required(VERSION 3.29)
project(Assignment3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment3
        common.c
        dllist.c
        dllist_ptest.c
        expression.c
        myrecord_sllist.c
        myrecord_sllist_ptest.c
        queue.c
        stack.c
        stack_ptest.c
        expression_ptest.c)
