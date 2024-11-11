t = int(input())

for it in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    a_i = [i for i in range(n)]

    for i in range(len(a_i)):
        a_i[i] = (i + a[i%n])%n

    if len(a_i) == len(set(a_i)):
        print("YES")
    else:
        print("NO")
