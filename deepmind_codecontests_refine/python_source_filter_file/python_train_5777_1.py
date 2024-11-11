n = int(input())
if n>=5:
    l = [i for i in range(1, n+1, 2)]
    l.extend([i for i in range(2, n+1, 2)])
    print(n, sep = '\n')
    print(*l)
elif n==4:
    print(3)
    print(*[1,4,2])
elif n==3:
    print(2)
    print(*[1,3])
else:
    print(1)
    print(1)
