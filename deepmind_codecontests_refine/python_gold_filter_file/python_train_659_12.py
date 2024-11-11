y,k,n = map(int,input().split())
noAnswer = False
if(y%k==0):
    s=y+k
else:
    s=y+k-y%k
while(s<=n):
    noAnswer=True
    print(s-y,end=" ")
    s+=k
if(not noAnswer):
    print(-1)