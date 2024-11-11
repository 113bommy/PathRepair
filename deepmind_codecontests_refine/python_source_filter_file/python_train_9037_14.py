n=int(input())
A=[int(input()) for _ in range(n)]

if A[0]!=0:print(-1);exit()

cnt,length=0,0
for i in range(n-1):
    if A[i]!=0:length +=1
    else:length=0

    if A[i]<=length:
        if A[i]+1==A[i+1]:cnt +=1
        elif abs(A[i]-A[i+1])>1:print(-1);exit()
        else:cnt +=A[i+1]
    else:print(-1);exit()
print(cnt)