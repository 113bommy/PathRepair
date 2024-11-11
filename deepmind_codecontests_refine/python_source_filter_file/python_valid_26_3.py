from sys import stdin

for _ in range(int(stdin.readline())):
    s = stdin.readline().strip()
    max_arr = [0, 0]
    min_arr = [0, 0]
    res = 10
    remaining = [0, 0]
    for i in range(10):
        if s[i] != '0':
            max_arr[i % 2] += 1
            if s[i] == '1':
                min_arr[i % 2] += 1
        remaining[i%2] -= 1
        if max_arr[0] - min_arr[1] > remaining[1] or max_arr[1] - min_arr[0] > remaining[0]:
            res = i + 1
            break
    print(res)
