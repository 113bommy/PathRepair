from math import factorial

N, A, B = map(int, input().split())
V = sorted(list(map(int, input().split())), reverse=True)

print(sum(V[:A]) / A)
if V[0] == V[A - 1]:
    n = sum([1 for v in V if v == V[0]])
    print(sum([factorial(n) // factorial(r) // factorial(n - r)
               for r in range(A, n + 1)]))
else:
    n = sum([1 for v in V if v == V[A - 1]])
    r = sum([1 for v in V[:A] if v == V[A - 1]])
    print(factorial(n) // factorial(r) // factorial(n - r))
