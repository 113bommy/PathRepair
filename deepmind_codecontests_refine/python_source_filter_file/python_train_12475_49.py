n, a, b = [int(i) for i in input().split()]
print(["Alice", "Boris"][(a - b) % 2])