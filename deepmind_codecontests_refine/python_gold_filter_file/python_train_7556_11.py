n = int(input())
if n < 10:
    print(1)
else:
    m = str(n)
    s = m[1:]
    print(10**len(s) - int(s))