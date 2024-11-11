n, k, M = map(int, input().split())
t = list(map(int, input().split()))

answer = []

for good in range(n + 1):
    local_answer = (k + 1) * good
    m = M - sum(t) * good
    if m < 0:
        print(m)
        continue
    todo = sorted(t * (n - good), key=lambda x: -x)
    # print(m, todo, local_answer)
    while todo and m:
        if m < todo[-1]:
            break
        m -= todo.pop()
        local_answer += 1
    answer.append(local_answer)
# print(answer)
print(max(answer))
