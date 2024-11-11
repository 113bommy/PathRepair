n,k1,k2 = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = []
for i in range(n):
    c.append(abs(a[i]-b[i]))
k = k1+k2
c.sort(reverse=True)
while(k!=0):
    if(c[0]==0):
        break
    c[0]-=1
    k-=1
    c.sort(reverse=True)
if(k!=0):
    if(k%2):
        ans = 1
    else:
        ans = 0
else:
    ans = 0
    for i in c:
        ans+=i
print(ans)