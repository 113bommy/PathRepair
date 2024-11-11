a, b = [int(i) for i in input().split()]

print(a+b if a % b == 0 else b-a)
