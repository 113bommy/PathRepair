#!/usr/bin/env python3

digit = input()
good_value = {'0': 2, '1': 6, '2': 2, '3': 3, '4': 3, '5': 3, '6': 2, '7': 5, '8': 1, '9': 2}

print(good_value[digit[0]] * good_value[digit[1]])
