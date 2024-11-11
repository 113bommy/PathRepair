ab, bc, ac = map(int, input().split())
a = (ab * ac / bc) ** .5
b = ab / a
c = ac / a
print(int(4 * (a + b + c)))