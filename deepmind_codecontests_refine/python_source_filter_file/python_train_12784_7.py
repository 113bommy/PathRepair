n,x=map(int,input().split())
l=[int(x) for x in input().split()]
print(sum([sum(l[:i])<=x for i in range(n)]))