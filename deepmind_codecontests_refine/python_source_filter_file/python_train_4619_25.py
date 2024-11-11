n = int(input())
c = 0
while n>0:
    a, b, c = map(int, input().split())
    sum = a+b+c
    if sum>=2: c += 1
    n -= 1
print(c)