n = int(input())
A = [int(input()) for i in range(n)]

print('second' if all(A[i] % 2 == 0 for i in range(n)) else 'first')
