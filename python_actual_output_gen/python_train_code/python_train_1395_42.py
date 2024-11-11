n=int(input())
l=[1,2]
for i in range(n):
    l.append(l[-1]+l[-2])
print(l[n-1])