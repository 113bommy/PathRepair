S = input()
T = input()

print(sum(s != t for s, t zip(S, T)))