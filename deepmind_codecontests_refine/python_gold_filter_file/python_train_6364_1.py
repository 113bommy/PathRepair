
n = int(input())
l = list(map(int,input().split()))
ans,mx=0,100000000
for i in range(1,101):
    c=0
    for j in l:
        if(abs(i-j)>1):
            c+=(abs(i-j)-1)
    if mx>c:
        mx=c
        ans=i
print(ans,mx)