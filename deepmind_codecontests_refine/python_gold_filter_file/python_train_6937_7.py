R = lambda : list(map(int, input().split()))
n, pos, l, r = R()

if(pos<l):
    if(r!=n): print(r-pos+2)
    else: print(l-pos+1)

elif(pos>r):
    if(l!=1):print(pos-l+2)
    else: print(pos-r+1)

else:
    if(l==1 and r==n): print(0)
    else:
        if(l==1): print(r-pos+1)
        elif(r==n): print(pos-l+1)
        else:print(min(pos-l,r-pos)+r-l+2)