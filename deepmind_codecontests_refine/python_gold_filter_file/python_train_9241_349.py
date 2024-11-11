K = int(input())
S = input()
L = len(S)

print(S if K >= L else S[:K] + '...')
