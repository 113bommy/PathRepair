t = int(input())
for i in range(t):
    q = [int(x) for x in input().split()]
    s = q[0]
    a = q[1]
    b = q[2]
    c = q[3]
    sh = s // c
    if sh > a:
        print(sh + (sh // a) * b)
    else:
        print(sh)



