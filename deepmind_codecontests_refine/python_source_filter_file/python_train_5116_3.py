R=lambda:map(int,input().split())
n,h=R()
a=list(R())
y=[]
k=0
for i in range(1,n):
    y=a[:i+1]
    y.sort(reverse=True)
    s=sum(y[::2])
    if(h>=s):
        k=i+1
    else:
        break
print(k)
