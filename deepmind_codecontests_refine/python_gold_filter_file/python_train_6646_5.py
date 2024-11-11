from collections import Counter

N, M = map(int, input().split())
A_list = []
for _ in range(N):
    a = list(map(int, input().split()))
    A_list.append(a)

ans = N
for _ in range(M-1):
    most_like_list = []
    for i in range(N):
        most_like_list.append(A_list[i][0])
    most_like, ans_new = Counter(most_like_list).most_common()[0]
    ans = min(ans, ans_new)
    for i in range(N):
        A_list[i].remove(most_like)

print(ans)
