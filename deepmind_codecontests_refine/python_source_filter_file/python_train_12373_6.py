from collections import Counter
n=int(input())
s=[input() for i in range(n)]
count=Counter(s[0])
for i in range(n):
    count &=s[i]

ans=""
for i in sorted(count.keys()):
    ans +=i*count[i]
print(ans)