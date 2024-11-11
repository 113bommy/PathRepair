n = int(input())
l = list(map(int,input().strip().split()))
m = 0
cnt=0
if n==1:
    print(1)
else:
    for i in range(0,n-1):
        if 2*l[i]>=l[i+1]:
            cnt+=1
        else:
            cnt=0
        if m < cnt:
            m = cnt
    print(m+1)
