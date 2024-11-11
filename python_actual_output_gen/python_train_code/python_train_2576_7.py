n, m = map(int, input().split())
print((m and (-m)).bit_length())