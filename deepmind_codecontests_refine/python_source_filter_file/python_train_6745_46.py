S = input()
n = 0
for i in range(len(S)//2):
    if S[i] != S[i-1]:
        n+=1
print(n)
