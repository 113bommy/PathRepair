x = int(input())
print([360*n//x for n in range(1, 1000) if 360 % x == 0][0])