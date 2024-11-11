S = {c:list(input()) for c in "abc"}

k = "a"
while len(S[k]):
    k = S[k].pop()

print(k.upper())