get_grade = lambda x, m, w:max( int(0.3*x), int((250 - m) * x / 250 - 50*w))

m1, m2, m3, m4, m5 = map(int, input().split(" "))
w1, w2, w3, w4, w5 = map(int, input().split(" "))
hs, hu = map(int, input().split(" "))
result = 100 * hs - 20 * hu
result += get_grade( 500, m1, w1)
result += get_grade( 1000, m2, w2)
result += get_grade( 1500, m3, w3)
result += get_grade( 2000, m4, w4)
result += get_grade( 2500, m5, w5)
print(result)

