S = {c:list(input()) for c in "abc"}

k = "a"
while len(S[k]):
    k = S[k].pop(0)

print(k.upper())