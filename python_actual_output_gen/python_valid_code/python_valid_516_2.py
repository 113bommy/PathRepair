from sys import stdin

for _ in range(int(stdin.readline())):
    s = stdin.readline().strip()
    max_arr = [0, 0]
    min_arr = [0, 0]
    res = 10
    even_remaining = 5
    odd_remaining = 5
    for i in range(10):
        if s[i] != '0':
            max_arr[i % 2] += 1
            if s[i] == '?':
                min_arr[i % 2] += 1
        if i % 2 == 0:
            even_remaining -= 1
        else:
            odd_remaining -= 1
        if max_arr[0] - min_arr[1] > odd_remaining or max_arr[1] - min_arr[0] > even_remaining:
            res = i + 1
            break
    print(res)
