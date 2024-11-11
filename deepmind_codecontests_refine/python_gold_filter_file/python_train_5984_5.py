a=list(input())
s=0
for i in set(a):
    s+=(a.count(i))**2
print(s)