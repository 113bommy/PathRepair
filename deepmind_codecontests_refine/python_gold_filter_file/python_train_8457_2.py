from sys import stdin

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    a = list(map(int, stdin.readline().split()))
    b = list(map(int, stdin.readline().split()))
    need_swap = False
    for i in range(n-1):
        if a[i] > a[i+1]:
            need_swap = True
            break
    res = 'Yes'
    if need_swap:
        has_both = False
        for i in range(n-1):
            if b[i] != b[i+1]:
                has_both = True
                break
        if not has_both:
            res = 'No'
    print(res)