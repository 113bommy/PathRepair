S = input()
print(len([True for s in range(len(S)//2) if S[i] != S[-1-i]]))