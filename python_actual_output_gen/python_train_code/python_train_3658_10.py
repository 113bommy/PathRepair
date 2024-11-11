min_a, max_b = 10 ** 10, 0
min_A, max_B = 10 ** 10, 0
cur_index = 0
for i in range(int(input())):
    a, b = map(int, input().split())
    if a < min_A:
        min_A = a
    elif b > max_B:
        max_B = b
    if a <= min_a and b >= max_b:
        min_a = a
        max_b = b
        cur_index = i + 1
if min_a == min_A and max_b == max_B:
    print(cur_index)
else:
    print(-1)
