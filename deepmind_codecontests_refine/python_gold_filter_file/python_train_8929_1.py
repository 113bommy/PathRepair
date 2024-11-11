from collections import Counter
n=int(input())
s=Counter([input()for _ in[0]*n])
m=s.most_common(1)[0][1]
r=sorted((k for k,v in s.items() if v==m))
for a in r:print(a)