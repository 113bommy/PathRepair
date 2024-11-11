#! bin/env python3
N = int(input())
a = input().strip()
print(a)
count = 0
for i in range(len(a)-1):
    if a[i] == a[i+1]:
        count += 1
print(count)
