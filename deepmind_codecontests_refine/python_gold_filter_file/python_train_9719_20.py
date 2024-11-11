from math import sqrt, ceil

s1, s2, s3 = map(int, input().split())
a = sqrt(s1 * s2 // s3)
b = sqrt(s3 * s1 // s2)
c = sqrt(s3 * s2 // s1)
print(int(a+b+c) * 4)
