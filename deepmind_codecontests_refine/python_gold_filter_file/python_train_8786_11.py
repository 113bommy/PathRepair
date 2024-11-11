from bisect import bisect_right
def intinp():
    return list(map(int,input().split()))
def fx(B,x):
    t=bisect_right(B,x)
    if t:
        if B[t-1]>=x:
            return t-1
        else:
            return t
    else: return 0
m=int(input())
A=intinp()
x,y=intinp()
B=[]
B.append(A[0])
for i in range(1,m):
    B.append(B[i-1]+A[i])
i=fx(B,x)
A.append(0)
B.append(0)
if i==-1: print(0)
else:
    while (x<=B[i]<=y and B[m-1]-B[i]>y and i<m):   i+=1
    if i+2<=m and x<=B[i]<=y and x<=B[m-1]-B[i]<=y:
        print(i+2)
    else:
        print(0)
