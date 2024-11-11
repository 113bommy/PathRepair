while 1:
    a = input()
    if a == '-':
        break
    n = int(input())
    for i in range(n):
        h = int(input())
        a = a[h:] + a[:h]
    print(a)
