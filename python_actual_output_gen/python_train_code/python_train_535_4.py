#!/usr/bin/env python3

n = int(input())
m = list(map(int, input().split()))
total = sum(m)
lower_avg = total // n
upper_avg = lower_avg + 1 if total > lower_avg * n else 0
result = max(sum(i - upper_avg for i in m if i > upper_avg),
             sum(lower_avg - i for i in m if i < lower_avg))
print(result)
