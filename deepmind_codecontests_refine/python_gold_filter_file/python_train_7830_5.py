n = int(input())
s = input()
cost, cur, ind = 0, 0, -1
for i in range(n):
    prev = cur
    cur += 1 if s[i]=='(' else -1
    if cur == 0:
        if prev < 0:
            cost += i-ind
        ind = i
print(-1 if cur else cost)