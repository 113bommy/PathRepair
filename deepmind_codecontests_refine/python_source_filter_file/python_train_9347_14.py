
n = int(input())
a = list(map(int,input().split()))
d = [0]

for i in range(n):
    d.append(d[i] ;a[i])

ans = d[-1]

for i in range(n):
    ans =min(ans,abs(d[-1] -2*d[i]))
print(ans)
