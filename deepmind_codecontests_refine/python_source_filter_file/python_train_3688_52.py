a = int(input())
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
ti = 0
for i in range(c[1]-1):
    ti = ti + b[i]
print(ti)
