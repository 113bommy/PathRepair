S,T = input(),input()
r = len(T)

for i in range(len(S)-len(T)+1):
    t = 0
    for j in range(len(T)):
        if S[i+j] != T[j]:
            t += 1
    r = min(r,t)

print(r)