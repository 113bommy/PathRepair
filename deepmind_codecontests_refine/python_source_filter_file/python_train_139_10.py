n = int(input())
g = [0]*101
sol = []
for _ in range(n):
    a,b = map(int,input().split())
    sol.append(a)
    
    g[a]+=1
ans = 0
for i in sol:
    ans+=g[i]
print(ans)