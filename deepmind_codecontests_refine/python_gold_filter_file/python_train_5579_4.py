from collections import Counter as c
a,b=map(int,input().split())
for _ in " "*b:
    z=c(list(map(abs,set(map(int,input().split()[1::])))))
    if max(z.values())==1:exit(print("YES"))
print("NO")