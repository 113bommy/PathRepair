S=input()
T=input()
print(sum([1 for i in range(len(S)) if S[i] == T[i]]))