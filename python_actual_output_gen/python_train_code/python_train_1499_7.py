x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
n = int(input())
steps = 0

for i in range(n):
    a, b, c = map(int, input().split())
    if ((a*x1 + b*x2 + c < 0) != (a*x2 + a*y2 + c < 0)):
        steps += 1

print(steps)
