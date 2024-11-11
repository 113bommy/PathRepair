N, C = map(int, input().split())
max_size = 10 ** 5
record_list = [[int(i) - 1 for i in input().split()] for _ in range(N)]
ans_list = [0 for _ in range(max_size)]
for c in range(C):
    T = [0 for _ in range(max_size + 1)]
    for s, t, i in record_list:
        if i == c:
            T[s] += 1
            T[t + 1] -= 1
    for i in range(max_size):
        T[i + 1] += T[i]
    for i in range(max_size):
        ans_list[i] += T[i]
print(max(ans_list))