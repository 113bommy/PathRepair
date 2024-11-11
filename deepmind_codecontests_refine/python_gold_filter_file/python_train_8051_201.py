n=int(input())
list=[int(x) for x in input().split()]
v=0
for i in range(n):
    v+=list[i]

print(v/n)