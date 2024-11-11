S = input()
T = input()

print(sum([i == j for i, j in zip(S, T)]))