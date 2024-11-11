y, k, n = map(int,input().split())
l1 = n%k
n-=(l1)
t = n-y
if t==0:
    print(-1)
elif y>=n:
    print(-1)
elif t<k:
    print(k-t) 
else:
    li = []
    for i in range(t,0,-k):
        li.append(i)
    print(*li[::-1])