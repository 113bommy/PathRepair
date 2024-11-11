S = list(input())
i, j = 0, len(S) - 1
ans = 0

while i != j:
    if S[i] == S[j]:
        i += 1
        j -= 1

    elif S[i] == 'x':
        i += 1
        ans += 1

    elif S[j] == 'x':
        j -= 1
        ans += 1

    else:
        print('-1')
        break

else:
    print(ans)
