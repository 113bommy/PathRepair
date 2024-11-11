v_num = int(input())
adjacent = [[0 for n in range(v_num)] for m in range(v_num)]
for _ in range(v_num):
    inp = [int(n) for n in input().split(" ")]
    for i in inp[2:]:
        adjacent[inp[0] - 1][i - 1] = 1
for i in range(v_num):
    print(*adjacent[i])