n=int(input())
d=[int(x) for x in input().split()]
l=[d.count(i) for i in set(d)]
print(n-max(d))