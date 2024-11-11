n=int(input())
ivy=[int(x) for x in input().split()]
pos=0
temp=0
j=0
ans=1
for i in range(1,n):
    if not ivy[i]-ivy[i-1]==0:
        if ivy[i]-ivy[i-1]==temp:
            j=pos+1
        temp=ivy[i]-ivy[i-1]
        pos=i-1
    ans = max(ans, i-j+1)
print(ans)