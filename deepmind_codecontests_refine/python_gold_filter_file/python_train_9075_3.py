s = input()
a = s.count('4')
b = s.count('7')
if a >= b and a > 0:
    print(4)
elif b >= a and b > 0:
    print(7)
else:
    print(-1)
    