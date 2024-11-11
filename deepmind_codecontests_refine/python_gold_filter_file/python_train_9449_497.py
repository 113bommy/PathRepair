a, b, c, d = [int(i) for i in input().split(" ")]

print(max(a*c, a*d, b*c, b*d))