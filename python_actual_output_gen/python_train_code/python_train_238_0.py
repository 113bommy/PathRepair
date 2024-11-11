y, k, n = map(int, input().split())
l = []
start = (y-(y%k) + k)
for i in range(start, n+1, k):
    l.append(i-10)

if(len(l)):
    print(*l)
else:
    print(-1)