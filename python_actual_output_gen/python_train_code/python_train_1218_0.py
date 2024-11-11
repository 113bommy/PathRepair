n = int(input())
x, y = [int(i) for i in input().split()]
print(y)
for i in range(n - 1):
    t, a = [int(i) for i in input().split()]
    c = max(-(-x//t), -(-y//a))
    x = t * c
    y = a * c
print(x + y)
