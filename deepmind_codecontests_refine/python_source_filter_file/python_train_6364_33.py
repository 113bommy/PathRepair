import math
def median(l):
    half = len(l) // 2
    l.sort()
    if not len(l) % 2:
        return round((l[half - 1] + l[half]) / 2.0)
    return l[half]
n=int(input())
L=list(map(int,input().split()))
avg=round(sum(L)/n)
L.sort()
med=median(L)
c=float("inf")
val=0
for b in range(max(min(avg,med)-1,1),max(avg,med)+1):
    temp=0
    for a in L:
        if(abs(a-b)>1):
            if(a>b):
                temp+=(a-b-1)
            else:
                temp+=(b-1-a)
    if(temp<c):
        c=temp
        val=b
print(val,c)
