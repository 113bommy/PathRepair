b=1
n=int(input())
a=[int(i) for i in input().split()]
for i in range(n):
    if a.count(a[i]) > b:
        b=a.count(a[i])
print(b)