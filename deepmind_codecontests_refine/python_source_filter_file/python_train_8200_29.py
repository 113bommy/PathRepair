N = input()
A = list(map(int, input().split()))

print('Yes' if len(A) == len(set(A)) else 'No')