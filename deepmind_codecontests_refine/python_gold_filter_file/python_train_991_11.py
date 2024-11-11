#!/usr/bin/env python3

# https://codeforces.com/problemset/problem/673/A
# Time complexity:  O()

def calculate_interesting_minutes(minutes_list):
    minutes_list.insert(0, 0)
    interesting_minutes = 0
    for i in range(len(minutes_list) - 1):
        if minutes_list[i+1] - minutes_list[i] > 15:
            interesting_minutes = 15 + minutes_list[i]
            break
    else:
        interesting_minutes = 15 + minutes_list[i+1]

    if interesting_minutes >= 90:
        interesting_minutes = 90
    return interesting_minutes

if __name__ == "__main__":
    n = int(input())
    minutes_list = list(map(int, input().split()))
    print(calculate_interesting_minutes(minutes_list))