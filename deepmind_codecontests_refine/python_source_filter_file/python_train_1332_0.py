S = input()
c = 0
S += ".."
while S[0] != ".":
    if S[0] != S[1]:
        c += 1
        S = S[1:]
    else:
        c += 2
        S = S[3:]
print(c)