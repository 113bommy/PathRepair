S = input()
T = input()
print(sum([1 if S[i]==T[i] else 0 for i in range(3)))