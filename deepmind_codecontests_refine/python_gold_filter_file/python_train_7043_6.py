I=lambda:map(int,input().split())
w,l=I()
a=list(I())
c=s=sum(a[:l])
for i in range(w-l-1):
    s=s-a[i]+a[i+l]
    c=min(c,s)
print(c) 