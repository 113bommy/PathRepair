K = int(input())
S = input()

n = len(S)
print(S if K >= n else S[:K] + "...")