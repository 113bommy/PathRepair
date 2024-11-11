n = int(input())
a, b = [int(i) for i in input().split()]
if max(a - 1, b - 1) > max(n - a, n - b):
    print("Black")
else:
    print("White")
