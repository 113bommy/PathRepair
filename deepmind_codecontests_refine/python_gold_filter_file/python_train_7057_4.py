S = list(input())
K = int(input())

if(len(set(S)) == 1):
    print(len(S) * K//2)
else:
    ans = 0
    cnt = 1
    a = []
    for i in range(len(S)-1):
        if(S[i] == S[i+1]):
            cnt += 1
        else:
            a.append(cnt)
            cnt = 1
    a.append(cnt)

    for i in a:
        ans += (i//2)*K

    if (S[0] == S[-1]):
        ans -= (a[0]//2 + a[-1]//2  - (a[0] + a[-1])//2)*(K-1)

    print(ans)