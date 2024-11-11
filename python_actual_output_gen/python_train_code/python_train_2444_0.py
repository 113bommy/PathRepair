N = int(input())
A = [int(_) for _ in input().split()]
 
ans = []
t = []
c = 0
for i in range(N):
    c += A[i]
    t.append(c)
    
l = 0
r = 0

for _ in range(2, N-1):
    while t[_] > t[l]+t[l+1]:
        l += 1
    while t[-1]+t[_] > t[r]+t[r+1]:
        r += 1
    n = [t[l], t[_]-t[l], t[r]-t[_], t[-1]-t[r]]
    ans.append(max(n)-min(n))
    
print(min(ans))