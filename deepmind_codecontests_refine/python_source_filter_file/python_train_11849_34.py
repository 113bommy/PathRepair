from collections import Counter
n = int(input())
s = list(input())
c = Counter(s)
ans = 1
for i in c.values():
    ans =  ans * ((i+1) % 1000000007)
print(ans-1)