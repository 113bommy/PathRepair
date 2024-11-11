from math import sqrt
for tt in range(int(input())):
    k=int(input())
    nk=int(sqrt(k))
    if k==nk**2:
        print(1,nk)
        continue
    below =  nk**2
    nk+=1
    diff = k-below
    if diff<=nk:
        print(diff,nk)
    else:
        diff-=nk
        print(nk,nk-diff)
    

