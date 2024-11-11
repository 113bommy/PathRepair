N = input()
A = list(map(int, input().split()))

print('Yes' if N == len(set(A)) else 'No')