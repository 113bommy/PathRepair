x, y = [int(x) for x in input().split()]
size = int(y/x).bit_length()
print(size)
