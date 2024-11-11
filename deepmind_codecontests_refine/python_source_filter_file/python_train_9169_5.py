b=1
n=int(input())
a=[int(i) for i in input().split()]
for i in range(n):
    if a.count(i) > b:
        b=a.count(i)
print(b)