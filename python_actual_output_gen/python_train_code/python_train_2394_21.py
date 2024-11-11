input()
cur = cnt = 0
for i in sorted(map(int, input().split())):
    if cur <= i:
        cnt += 1
    cur += 1
print(cnt)