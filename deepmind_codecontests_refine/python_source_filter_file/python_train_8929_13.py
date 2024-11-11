import collections
n=int(input())
s=[]
for _ in range(n):
    s.append(str(input()))
ans=collections.Counter(s)
a=max(ans.values())
ans=[i for i,k in ans.items() if a==k]
print(*ans.sort(),sep="\n")