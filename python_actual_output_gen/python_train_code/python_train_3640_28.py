n,k=map(int,input().split())
cnt=0
while n>1:
    n=n/k
    cnt+=1
print(cnt)