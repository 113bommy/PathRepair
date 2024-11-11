l,r= map(int, input().split())
if l%2==0 and r-l+1==3:
    print(l,l+1,l+2)
elif r-l+1<3:
    print(-1)
elif l%2==0:
    print(l,l+1,l+2)
elif r-l+1>3:
    print(l+1,l+2,l+3)