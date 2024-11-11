[n, B] = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
even = 0
odd = 0
i = 0
B1 = []
if n&1:
    print("0")
else:
    while(i < n - 2):
        if A[i] & 1:
            odd += 1
        else:
            even += 1
        if odd == even:
            B1.append(abs(A[i+1] - A[i]))
        i += 1
    B1.sort()
    s = 0
    i = 0
    c = 0
    while(i < len(B1)):
        s += B1[i]
        c += 1
        if s > B:
            c -= 1
            s -= B1[i]
            break
        i += 1
    print(c)
