h = int(input().split())
print(2 ** (len(bin(h)) - 2) - 1)