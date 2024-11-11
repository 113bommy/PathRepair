K, T = map(int, input().split())
A = list(map(int, input().split()))

print(max(0, max(A) - (K-max(A)+1)))