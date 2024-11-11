from sys import stdin
input = stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = input().rstrip()
    b = input().rstrip()

    out = []
    for i in range(n - 1):
        if i % 2 == 0:
            if b[n - i - 1] == a[i // 2]:
                out.append(1)
                out.append(n - i)
            else:
                out.append(n - i)
        else:
            if b[n - i - 1] != a[n - (i // 2) - 1]:
                out.append(1)
                out.append(n - i)
            else:
                out.append(n - i)

    if (n - 1) % 2 == 0:
        if a[(n - 1) // 2] != b[0]:
            out.append(1)
    else:
        if a[n - ((n - 1) // 2) - 1] != b[0]:
            out.append(1)
    

    print(len(out), *out)
