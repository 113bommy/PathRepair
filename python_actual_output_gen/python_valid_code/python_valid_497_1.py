def solution(n, ratings, likes):
    ans = [0 for _ in ratings]
    c = 1
    posL = []
    posR = []
    for i, l in enumerate(likes):
        if l == '0':
            posL.append((i, ratings[i]))
        else:
            posR.append((i, ratings[i]))
    
    for idx, _ in sorted(posL, key=lambda x: x[0]):
        ans[idx] = c
        c += 1

    for idx, _ in sorted(posR, key=lambda x: x[1]):
        ans[idx] = c
        c += 1
    
    return ans

for _ in range(int(input())):
    n = int(input())
    ratings = list(map(int, input().strip().split()))
    likes = list(input().strip())

    print(*solution(n, ratings, likes))