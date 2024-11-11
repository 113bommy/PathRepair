#E
N=int(input())
ans=0
if N%2==0:
    N=N/2
else:
    N=-1
cnt=1
while cnt<=N:
    cnt*=5
    ans+=N//cnt
print(int(ans))