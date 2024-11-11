I=lambda:map(int,input().split())
w,l=I()
a=list(I())
c=s=sum(a[:l])
for i in range(w-l-2):
    s=s-a[i]+a[i+l+1]
    c=min(c,s)
print(c) 