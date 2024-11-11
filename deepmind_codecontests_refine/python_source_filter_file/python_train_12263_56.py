n = int(input())
r = (25*n + 24)//27
print((r, ':')[r * 27 < n])
