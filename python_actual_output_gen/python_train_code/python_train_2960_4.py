n , k = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))

for i in range(n):
    b[i]-=a[i]
c = list(zip(a,b))
c = sorted(c,key = lambda x:-x[1])
ans = 0
z = 0
print(c)
for i in range(n):
    if c[i][1]>=0 or z<k:
        ans+=c[i][0]
        z+=1
    else :
        ans+= c[i][0]+c[i][1]
print(ans)
    
