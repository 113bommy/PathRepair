t = int(input())

for i in range(t):
    b = input()
    if len(b) == 2:
        a = b
    else:
        a = b[0]
        for j in range(1, len(b), 2):
            a += b[j]
        a += b[-1]
    print(a)