n = int(input())
A = [int(x) for x in input().split()]
if (A[n] == A[n - 1]): print("NO")
else: print("YES")
