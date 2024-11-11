a=input().split()
print(*a)
c=int(input())
for x in range(c):
    g,h=input().split()
    a[a.index(g)]=h
    print(*a)
