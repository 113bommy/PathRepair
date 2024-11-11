n = int(input()); V = 0
if n > 2:
    for i in range(n):
        L = [int(x) for x in input().split()]
        if i == 0.5*(n-1):
            V += sum(L)
        else:
            V += L[i] + L[int((n-1)/2)] + L[n-i-1]
    print(V)
else:
    print(int(input()))