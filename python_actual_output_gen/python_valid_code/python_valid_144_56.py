n,c=input().split()
n=int(n)
c=int(c)
a=[n]
x=0
a=list(map(int,input().split()))
for i in range (1,n):
    if a[i]-a[i-1]>c:
        x=1
    else:
        x+=1
print(x)