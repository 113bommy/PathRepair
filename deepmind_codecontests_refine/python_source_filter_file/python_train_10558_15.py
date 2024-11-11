l,r = input().split("|")

n = input()

if len(r)<len(l):
    if len(n) + len(r) < len(l):
        print("Impossible")
    elif len(n) + len(r) == len(l):
        r+=n
        print(l+"|"+r)
    else:
        if ((len(n) + len(r) + len(l)) %2 !=0):
            print("Impossible")
        else:
            toR,toL = n[0:len(l)-len(r)],n[len(l)-len(r):]
            r+=toR
            h1,h2=toL[0:len(toL)//2],toL[len(toL)//2:]
            l+=h2
            r+=h1
            print(l+"|"+r)

elif len(l) == len(r):
    if (len(n) %2 != 0):
        print("Impossible")
    else:
        h1,h2=n[0:len(n)//2],n[len(n)//2:]
        l+=h2
        r+=h1
        print(l+"|"+r)

else:
    if len(n) + len(l) < len(r):
        print("Impossible")
    elif len(n) + len(l) == len(r):
        l+=n
        print(l+"|"+r)
    else:
        if ((len(n) + len(r) + len(l)) %2 !=0):
            print("Impossible")
        else:
            toR,toL = n[0:len(r)-len(l)],n[len(r)-len(l):]
            r+=toL
            h1,h2=toL[0:len(toL)//2],toL[len(toL)//2:]
            l+=h2
            r+=h1
            print(l+"|"+r)
