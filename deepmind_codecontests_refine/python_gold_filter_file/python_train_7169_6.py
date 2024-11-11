for _ in range(int(input())):
    ax, ay, bx, by, cx, cy, dx, dy = map(float, input().split())
    print(['NO','YES'][abs((ay-by)*(dx-cx)-(ax-bx)*(dy-cy))<1e-10])