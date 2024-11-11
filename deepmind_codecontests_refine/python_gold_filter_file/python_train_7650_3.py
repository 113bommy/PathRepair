
prime = []
f = [0]*1001
f[0] = f[1] = 1
for i in range(2,1001):
    if f[i]==0:
        for j in range(i*i,1001,i):
            f[j] = 1
n = int(input())

ans = []
for i in range(2,n+1):
    if f[i]==0:
        j = i
        while j<=n:
            ans.append(j)
            j*=i
print(len(ans))
print(*ans)