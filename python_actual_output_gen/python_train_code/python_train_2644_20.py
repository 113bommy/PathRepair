n,m = map(int, input().strip().split())
h = n//2
ans = 0
cur = 0
for i in range(1,min(m,h)+1):
    ans += 1
    cur += 1
if m > h and m%2:
    cur += 1
if m > cur:
    for i in range(cur+1,m+1):
        ans-= 1
if m == 0:
    print (1)
else:
    print(ans)