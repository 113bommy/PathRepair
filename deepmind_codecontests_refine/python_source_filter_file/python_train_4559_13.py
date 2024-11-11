A, B, M = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

ans = min(a)+min(b)

for i in range(M):
    x,y,c = map(int, input().split())
    ans = min(ans,a[x-1]+b[x-1]-c)

print(ans)