number = int(input())
scoreArray = list(map(int,input().split()))
A = set(scoreArray)
ans = 0
for i in A:
    if i==0:
        continue
    else:
        ans+=1
print(ans)