A, B, K = map(int, input().split())

ans = [i for i in range(1, A+1) if A % i == 0 and B % i == 0]
print(ans[K])
