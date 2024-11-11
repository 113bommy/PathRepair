def mex():
    hashi=dict()
    for i in li:
        hashi[i]=1
    for i in range(n+1):
        if i not in hashi:
            return i
t=int(input())
for you in range(t):
    n=int(input())
    l=input().split()
    li=[int(i) for i in l]
    hashno=dict()
    for i in range(n):
        if(li[i]!=i):
            hashno[i]=1
    lo=[]
    while(len(hashno)>0):
        z=mex()
        if(z<n):
            li[z]=z
            lo.append(z)
            del hashno[z]
        else:
            for i in hashno:
                li[i]=n
                lo.append(i)
                break
            z=mex()
            lo.append(z)
            li[z]=z
            del hashno[z]
    print(len(lo))
    for i in lo:
        print(i,end=" ")
    print()