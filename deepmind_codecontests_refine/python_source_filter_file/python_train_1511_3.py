n = int(input())
l = [0] * (10**6+5)
for i in map(int,input().split()):
    l[i] += 1
cur = ans = 0
for i in l:
    cur += i
    if cur%2:
        ans += 1
    cur //=2
print (ans)
