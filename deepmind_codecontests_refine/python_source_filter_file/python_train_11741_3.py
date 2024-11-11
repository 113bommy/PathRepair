n=int(input()) ; n+=1
A=list(map(int,input().split()))
if n==0:
    if A[0]==1: print(1);exit()
    print(-1);exit()
if A[0]!=0:print(-1);exit()
ANS=[0]*n ;ANS[0]=1
R=[0]*n
for i in range(n-2,-1,-1):
    R[i]=R[i+1]+A[i+1]
#print(R)
for i in range(1,n):
    ANS[i]=min(ANS[i-1]*2-A[i], R[i])
    if ANS[i]<0:print(-1);exit()
print(sum(A)+sum(ANS))