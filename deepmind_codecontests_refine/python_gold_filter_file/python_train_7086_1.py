while True:
    a = input()
    if a == '-':
        break
    n = int(input())
    for i in range(n):
        hi = int(input())
        a = a[hi:] + a[:hi]
    print(a)
