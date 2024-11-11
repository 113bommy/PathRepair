# from bisect import bisect_left
TC = int(input())

for tc in range(TC):
    N = int(input())
    S = input()
    # print(N, S)
    result = [S[i] for i in range(N)]
    # print(result)
    pos = 1
    for j in range(1, N):
        if result[pos] != S[j + pos]:
            result[pos] = S[j + pos]
            pos += 1

    print(''.join(result))
