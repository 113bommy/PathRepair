a, b, c, k = [int(i) i in input().split(" ")]
print(min(a, k) - max(0, k-a-b))
