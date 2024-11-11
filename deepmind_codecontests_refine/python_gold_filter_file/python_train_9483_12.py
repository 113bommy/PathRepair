n,m = map(int,input().split())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
i = 0
j = 0
ans = 0
while(j<m and i<n):
    if(l2[j]>=l1[i]):
        j+=1
        i+=1
        ans+=1
    else:
        i+=1
print(ans)