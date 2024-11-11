N, K = map(int, input().split())
print(sorted(map(int, input().split()), reverse=True)[:K])