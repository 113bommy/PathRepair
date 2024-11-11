def find_points(l1, r1, l2, r2):
    lmin = min(l1, l2)
    return (l1, r2) if l1 == lmin else (r1, l2)


for i in range(int(input())):
    print(*find_points(*list(map(int, input().split()))))
