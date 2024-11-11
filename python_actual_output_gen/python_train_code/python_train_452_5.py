t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(x) for x in input().split()]
    mini=int(1e9+7)
    maxi=-int(1e9+7)
    sumi=0
    flagi=-1
    for x in a:
        if flagi==-1:
            if x<0: flagi=0; mini=x
            else: flagi=1; maxi=x
        elif flagi==0:
            if x<0: mini=min(mini,x)
            else: flagi=1; maxi=x; sumi+=mini
        else:
            if x>0: maxi=max(maxi,x)
            else: flagi=0; mini=x; sumi+=maxi
    if flagi==0: sumi+=mini
    else: sumi+=maxi
    print(sumi)