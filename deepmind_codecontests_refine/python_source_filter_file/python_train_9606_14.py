import math
for z in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    temp=[]
    for i in range(n):
        temp.append(len(bin(a[i])))
    p=[]
    for j in range(1,32):
        p.append(j)
    ans=0
    for ii in p:
        cnt=temp.count(ii)
        ans+=int(cnt*(cnt-1)/2)
    print(ans)