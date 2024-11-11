n,m=map(int,input().split())
cnt=0
while 1:
    if m<=n:
        cnt+=n-m
        break
    if m%2:
        cnt+=1
        m+=1
    m//=2
    cnt+=1
print(cnt)
