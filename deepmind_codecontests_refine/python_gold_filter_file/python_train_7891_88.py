S=input()
N=len(S)
print(min([abs(753-int(S[i:i+3])) for i in range(N-2)]))