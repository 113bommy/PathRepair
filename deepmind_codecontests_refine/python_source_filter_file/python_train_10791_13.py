from math import ceil,floor
def findAP(a, d, size):
    ap = []
    for i in range(size):
        nth = a+(i)*d
        ap.append(nth)
    return ap
n = int(input())
b = list(map(int, input().split()))
if n==1:
    print(b[0])
    exit()
tot = 0
for i in range(1,n):
    tot += b[i]-b[i-1] 
if tot<0:
    cd = floor(tot/(n-1))
else:
    cd = ceil(tot/(n-1))
globalArr = []
for d  in (cd,cd+1,cd-1):
    ap1 = findAP(b[0],d,n)
    ap2 = findAP(b[0]+1,d,n)
    ap3 = findAP(b[0]-1,d,n)  
    for each in (ap1,ap2,ap3):
        val = 0
        flag = True
        for j in range(n):
            if(abs(each[j]-b[j])) <= 1:
                val += abs(each[j]-b[j])
            else:
                flag = False
                break
        if flag:
            globalArr.append(val)
if globalArr:
    print(min(globalArr))
else:
    print(-1)
