t = int(input()) # num of testcase

for i in range(t):
    size_a, size_b = [int(s) for s in input().split(' ')]
    a = [int(s) for s in input().split(' ')]
    b = [int(s) for s in input().split(' ')]
    set_a = set(a)
    set_b = set(b)

    has_common = False
    for j in range(1, 1000):
        if j in set_a and j in set_b:
            has_common = True
            print('YES')
            print('1 {}'.format(j))
            break
    if not has_common:
        print('NO')

