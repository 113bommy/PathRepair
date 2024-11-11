n,k,m = map(int,input().split())
a = sorted(list(map(int,input().split())))
a = [0]+a
s = sum(a)
ans = 0
m+=1
for i in range(n):
    s -=a[i]
    m-=1
    ans = max(ans,(s+min((n-i)*k,m))/(n-i))
    if(m==0):break
print(ans)