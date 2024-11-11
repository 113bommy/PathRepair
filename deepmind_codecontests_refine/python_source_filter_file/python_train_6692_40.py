import sys
import math

tests = int(sys.stdin.readline().split()[0])

for test in range(tests):
    x = int(sys.stdin.readline().split()[0])

    key_pressed = 0
    n = 1
    digit = 0
    test_number = 1

    if x == 1:
        print(1)
        exit()

    while test_number != x:
        digit += 1
        test_number = 0

        for k in range(4):
            test_number += digit * math.pow(10, k)
            key_pressed += int(math.log(test_number, 10)) + 1

            if test_number == x:
                break
        if test_number == x:
            break
    print(key_pressed)