n, k = map(int, input().split())
print((k & (-k)).bit_length())