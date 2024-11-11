[n, m] = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
for i in a:
    if i in b:
        print(a, end = ' ')