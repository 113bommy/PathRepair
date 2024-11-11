n, t = map(int, input().split())
arr = [0] * 101
students = [int(x) for x in input().split()]
cur_time = 0
for i in students:
    cur_time += i
    ptr = 100
    this = cur_time
    acc = 0
    while ptr:
        if this - arr[ptr] * ptr <= t:
            acc += (this - t - 1) // ptr + 1
            break
        else:
            acc += arr[ptr]
            this -= arr[ptr] * ptr
        ptr -= 1
    print(max(0, acc), end=' ')
    arr[i] += 1