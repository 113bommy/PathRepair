S = input()
T = input()
print(sum([int(s == t) for s, t in zip(S, T)]))
