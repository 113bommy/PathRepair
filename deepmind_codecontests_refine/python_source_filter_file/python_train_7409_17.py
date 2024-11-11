


n,d = map(int,input().split())



t= list(map(int,input().split()))


import math



p=0
for k in range(n-1):
    if t[k]==t[k+1]:
        p+=1
        t[k+1]+=d
    elif t[k]> t[k+1]:
        if (t[k]-t[k+1])%d==0:
            p+=math.ceil((t[k]-t[k+1])/d)+1
            t[k+1]+=math.ceil((t[k]-t[k+1])/d)*d+1
        else:
            p+=math.ceil((t[k]-t[k+1])/d)
            t[k+1]+=math.ceil((t[k]-t[k+1])/d)*d


print(p)
