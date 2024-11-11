K = int(input())
S = input()
N = len(S)
print(S if K >= N else S[:K] + '...')