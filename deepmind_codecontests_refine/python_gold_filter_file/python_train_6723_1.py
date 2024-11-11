A = int(input())
B = int(input())
if A < B:
    T = A
    A = B
    B = T
X = A- B
if X % 2 == 1:
    print(-1)
else:
    X //= 2
    print('{0} {1}'.format(int(X), int(A - X)))
