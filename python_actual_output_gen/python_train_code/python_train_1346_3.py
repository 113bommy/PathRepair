n, m = map(int, input().split())
a = [['.' for j in range(m)] for i in range(n)]
for i in range(n//2 + 1):
    a[2*i] = ['#' for i in range(m)]
    if i != n//2:
        if i % 4 == 0:
            a[2*i +1][-1] = '#'
        else:
            a[2*i +1][0] = '#'
for i in a:
    for j in i:
        print(j, end='')
    print()
