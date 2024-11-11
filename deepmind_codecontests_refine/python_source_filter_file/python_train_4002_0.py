def f(t): return  len(t) > 5 and any('0'<= i <= '9' for i in t) and any('A' <= i <= 'Z' for i in t) and any('A' <= i <= 'Z' for i in t)
print('Correct' if f(input()) else 'Too weak')