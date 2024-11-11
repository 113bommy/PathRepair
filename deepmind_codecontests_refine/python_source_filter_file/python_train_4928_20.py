n,a,b=map(int,input().split())
l=[int(x) for x in input().split()]
l.sort()
print(l)
print(l[b]-l[b-1])