n,m = map(int,input().split())
a = list(map(int,input().split()))
l = 0
for i in range(len(a)-1):
    if(a[i]>a[i+1]):
        l+=(n)
l-=1
if(l==0):
    l+=a[-1]-1
else:
    l+=a[-1]
print(l)
