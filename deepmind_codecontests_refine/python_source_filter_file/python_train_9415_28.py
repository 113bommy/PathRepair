n,d=list(map(int,input().split()))
C=list(map(int,input().split()))
sumC=0
_Ans=True
for i in range(n):
    sumC+=C[i]
if sumC+10*(n-1)>=d:
    _Ans=False
if not _Ans: print(-1)
else: print(int((d-sumC)/5))