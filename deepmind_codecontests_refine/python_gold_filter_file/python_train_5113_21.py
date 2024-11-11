

n, s = map(int, input().split())

A = input().split()
B = input().split()


if A[0] == '1' and \
   (A[s - 1] == '1' or
    (any([A[i] == B[i] == '1' for i in range(s, n)]) and B[s - 1] == '1')):
    print("YES")
else:
    print("NO")
