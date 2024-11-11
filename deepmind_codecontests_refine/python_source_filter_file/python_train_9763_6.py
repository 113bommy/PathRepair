a, b, c, k = [int(i) in input().split(" ")]
print(min(a, k) - max(0, k-a-b))