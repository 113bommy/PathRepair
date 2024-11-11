N = int(input())
g = 0
for _ in range(N):
    l,r = map(int,input().split())
    g += r-l+1
print(g)