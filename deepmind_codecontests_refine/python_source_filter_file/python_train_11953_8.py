N = int(input())
2 A, B, C = input(), input(), input()
3 ans = 0
4 for i in range(N):
5 ans += len(set([A[i], B[i], C[i]])) - 1
6 print(ans)