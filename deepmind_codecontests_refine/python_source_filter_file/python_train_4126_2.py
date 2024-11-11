n=int(input())
d=max(0,n-100)
a=[]
while d<n:
    p=n-d
    r,t=0,p
    while t:
        r+=t%10
        t//=10
    if r+p==n:a.append(p)
    d+=1
print(len(a))
for i in a:
    print(i)