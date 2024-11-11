n, m = map(int, input().split())
print((m & (-m)).bit_length())