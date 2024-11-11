import bisect
n,m=map(int,input().split())
l=[int(i) for i in input().split()]
m=[int(i) for i in input().split()]
s=0
psa=[]
for i in l:
    s+=i
    psa.append(s)
for i in m:
    t=bisect.bisect_left(psa,i)
    if i<=l[0]:
        print(t+1,i)
    else:    
        print(t+1,i-psa[t-1])