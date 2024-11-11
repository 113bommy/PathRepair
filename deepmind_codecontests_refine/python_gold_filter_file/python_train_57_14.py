a=input().split()
n=int(input())
print(*a)
for i in range(n):
    b,c=input().split()
    a[a.index(b)]=c
    print(*a)