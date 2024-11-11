k, a, b = (int(x) for x in input().split())
print((b - a) // k + (b%k < a%k) + (b%k == a%k == 0))
