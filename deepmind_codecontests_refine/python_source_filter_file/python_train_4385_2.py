x, y, z, t1, t2, t3 = [int(x) for x in input().split()]

a = abs(y - x) * t1
b = abs(z - x) * t2 + abs(x - y) * t2 + t3 * 2
print('YES' if b <= a else 'NO')