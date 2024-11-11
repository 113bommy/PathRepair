N = int(input())
A = sum(list(map(int, list(str(N)))))
if A == 1:
    print(5)
else:
    print(A)