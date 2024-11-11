#C. The Child and Toy
n, m = [int(x) for x in input().split()]
v = [int(x) for x in input().split()]
ans = 0
for _ in range(m):
    x, y = [int(x) for x in input().split()]
    #print(min(v[x-1],v[y-1]))
    ans += min(v[x-1], v[y-1])
print(ans)