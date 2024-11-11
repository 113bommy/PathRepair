n, k = [int(x) for x in input().split()]

l = n // (2*k+1) + (0 if n // (2*k+1) == 0 else 1)

al = (2*k+1)*l - n
ss = list(range(max(k - al, 1), n, 2*k+1))

print(l)
print(*ss)
