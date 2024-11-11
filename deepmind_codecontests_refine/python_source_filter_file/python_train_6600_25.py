from fractions import Fraction
from math import gcd
a,b,c,d = map(int,input().split())
area = a*b
x_num = a*d
x_den = c
x = x_num/x_den
area1 = x*a
y_num = b*c
y_den = d
y = y_num/y_den
print(x_num,x_den)
area2 = y*b
if area2>area or y>a:
    area2 = 0
if area1>area or x>b:
    area1 = 0

if area1>=area2:
    left_num = b*x_den - x_num
    # print(left)
    p_num = left_num*a
    p_den = x_den
    hm_num = p_num
    hm_den = p_den*area
    z = gcd(hm_num,hm_den)
    ans_num = hm_num//z
    ans_den = hm_den//z
    # print(hm)
    ans = str(ans_num)+'/'+str(ans_den)
if area1<=area2 :
    # left = a - y
    # p = left*b
    # hm = p/area
    # ans = Fraction(hm)

    left_num = a*y_den - y_num
    # print(left_num)
    p_num = left_num*b
    p_den = y_den
    hm_num = p_num
    hm_den = p_den*area

    z = gcd(hm_num,hm_den)
    ans_num = hm_num//z
    ans_den = hm_den//z
    # print(hm)
    ans = str(ans_num)+'/'+str(ans_den)

print(ans)
