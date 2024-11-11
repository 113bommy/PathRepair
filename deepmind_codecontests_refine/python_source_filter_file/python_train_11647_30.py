

S = input()
N = len(S)
for i in range(N):
    if i < N-1:
        if len(set(S[i:i+2])) == 1:
            print(i, i+2)
            exit()

    if i < N-2:
        if len(set(S[i:i+3])) <= 2:
            print(i, i+3)
            exit()

print(-1,-1)