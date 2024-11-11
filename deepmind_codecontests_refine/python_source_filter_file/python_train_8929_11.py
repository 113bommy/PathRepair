from collections import Counter

n=int(input())
S=[input() for _ in range(n)]

c=Counter(s)
m=max(c.values())
ans = sorted(k for k,v in c.items() if v == m)
print("\n".join(ans))