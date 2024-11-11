c,v0,v1,a,l=map(int,input().split())
s=0
i=0
while c>s:
    s+=min(v0,v1)
    v0+=a
    if not i:
        s-=l
    i+=1
print(i)
    
