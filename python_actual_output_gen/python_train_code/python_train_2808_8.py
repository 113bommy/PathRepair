def f(a, b):
    f1 = a + b in ('pq', 'qp', 'bd', 'db')
    f2 = a == b and a in 'AHIiMOoTUVvWwXxYZz'
    return f1 or f2
    
s = input()
n = len(s)
for i in range(n):
    if not f(s[i], s[n - i - 1]):
        print('NIE')
        break
else:
    print('TAK')
