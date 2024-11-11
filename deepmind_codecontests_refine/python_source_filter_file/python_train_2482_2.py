S = input()[::-1]
T = input()[::-1]

for i in range(len(S)-len(T)+1):
    for j in range(len(T)):
        if T[j] != S[i+j] != '?':
            break
    else:
        break
else:
    print('UNRESTORABLE')
    exit()

ans = (S[:i] + T + S[len(T)-i:])[::-1]
ans = ans.replace('?', 'a')
print(ans)