n, t = int(input()), input()[:: 2]
a, b = t.count('1'), t.count('2')
print(n - min(a, b, n - a - b))