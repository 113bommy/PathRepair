from collections import Counter
N=int(input())
arr=Counter(input()[1:N+1])
ans=0
for key,value in arr.items():
    ans+=value
print(ans+1)