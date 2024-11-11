n,l=map(int,input().split( ))

s=2*l+n-1

if l>0:
    s-=l
elif l==0:
    pass
elif l+n<=0:
    s-=l+n-1

print(s)