N, X = map(int, input().split())
a = [int(input()) for i in range(N)]
print(int((X-sum(a))/min(a)))
