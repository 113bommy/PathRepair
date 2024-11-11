a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())
a, b, c, d = c-a, d-b, e-c, f-d
cp = a*d - b*c
if cp > 0: print('LEFT')
elif cp == 0: print('TOWARDS')
else: print('RIGHT')
