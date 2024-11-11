n,m=map(int,input().split())
if m%n!=0:
    print(-1)
else:
    m=m//n
    cnt=0
    while m%2==0:
        cnt+=1
        m=m//2
    while m%3==0:
        cnt+=1
        m=m//3
    if m==0:
        print(cnt)
    else:
        print(-1)