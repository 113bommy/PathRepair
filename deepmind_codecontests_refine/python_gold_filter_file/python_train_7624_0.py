n = int(input())
 
for i in range(n):
    a, b = [int(s) for s in input().split()]
    a, b = min(a, b), max(a, b)
    if 2 * a >= b:
        print(4 * a * a)
    else:
        print(b * b)
