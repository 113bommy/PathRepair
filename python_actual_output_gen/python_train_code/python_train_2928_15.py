n,k = map(int,input().split())
s = list(map(int,list(input())))
x = [-1]
for i in range(n-1):
    if s[i] != s[i+1]:
        x.append(i)
x.append(n-1)
t = len(x)
ans = 1

for i in range(t-1):
    if i == 0:
        ans = max(ans,x[min(t-1,i+2*k)]-x[i])
    else:
        ans = max(ans,x[min(t-1,i+2*k+1)]-x[i])

print(ans)