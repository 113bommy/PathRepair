# https://codeforces.com/contest/709/problem/A

n, b, d = map(int, input().split())
oranges = map(int, input().split())

total = 0
count = 0
for i in oranges:
    if i >= b:
        continue
    else:
        total += i
        if total > d:
            count += 1
            total = 0


print(count)
