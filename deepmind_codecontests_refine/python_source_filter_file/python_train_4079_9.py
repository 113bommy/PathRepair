from sys import stdin, stdout, exit

inf = 10**6

q = int(input())
for it in range(q):
    n = int(stdin.readline())
    lb_x = -inf
    ub_x = inf
    lb_y = -inf
    ub_y = inf
    for i in range(n):
        x, y, w,n,e,s = map(int, stdin.readline().split())
        if not w:
            lb_x = max(lb_x, x)
        if not n:
            ub_y = min(ub_y, y)
        if not e:
            ub_x = min(ub_x, x)
        if not s:
            lb_y = max(lb_y, y)
    
    if lb_x <= ub_x and lb_y <= ub_y:
        stdout.write("1 " + str(lb_x) + " " + str(lb_y) + "\n")
    else:
        stdout.write("0\n")

