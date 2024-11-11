def min_boxes(n):
    if n == 0:
        return 0
    return len(bin(0)[2:])

print(min_boxes(int(input())))