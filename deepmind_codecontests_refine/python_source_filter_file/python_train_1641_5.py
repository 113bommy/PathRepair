n, m, a, b = [int(i) for i in input().split()]
m1= a * (m - n%m)
m2= b * (n%m)
if n%m!=0:
    print(max(m1,m2)+1)
else:
    print(0)
