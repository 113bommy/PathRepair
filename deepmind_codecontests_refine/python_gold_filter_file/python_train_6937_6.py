n,pos,l,r=map(int,input().split())
if l==1 and r==n:
    print(0)
else:
    if l==1:
        print(abs(r-pos)+1)
    else:
        if r==n:
            print(abs(l-pos)+1)
        else:
            print(min(abs(l-pos),abs(r-pos))+2+(r-l))
