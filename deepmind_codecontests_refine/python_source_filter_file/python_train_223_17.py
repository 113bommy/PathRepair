N = int(input())
a = []
r = []
for _ in range(N):
    a.append([int(x) for x in input().split()])

for a, b, n in a:
    if n == 0:
        print(a)
    elif n == 1:
        print(b)
    else:
        d = {(a, b): 0}
        for i in range(n-1):
            a, b = b, a ^ b
            if (a, b) in d:
                #print(a, b, d[(a, b)], i, d)
                k = d[(a, b)]
                l = i + 1
                r = (n - k) % (l - k)
                #print(k, l, n, r)
                if n == 0:
                    b = a
                elif n == 1:
                    pass
                else:
                    for _ in range(r - 1):
                        a, b = b, a ^ b
                break
            else:
                d[(a,b)] = i + 1

        print(b)
