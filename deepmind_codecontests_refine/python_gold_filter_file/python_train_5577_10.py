n, a, b, c = map(int, input().split(' '))

if n%4 == 3: print(min(a, 3*c, c+b))
elif n%4 == 2: print(min(2*a, b, 2*c))
elif n%4 == 1: print(min(3*a, a+b, c))
else: print(0)