a=input().split()
print(*a)
c=int(input())
for i in range(c):
    d,e=input().split()
    a[a.index(d)]=e
    print(*d)