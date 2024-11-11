n,m,d = map(int,input().split())

if d == -1 :
    ans = (m-1)/n
else :
    ans = (2*(n-d)*(m-1))/(n**2)

print(ans)
