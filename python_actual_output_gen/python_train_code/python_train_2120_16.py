n = int(input())
a, b = [int(i) for i in input().split()]
if max(a - 1, b - 1) > max(n - a, b - a):
    print("Black")
else:
    print("White")
