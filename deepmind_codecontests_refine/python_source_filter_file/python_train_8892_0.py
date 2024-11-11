a, d = map(float, input().split())
n = int(input())
for i in range(1, n + 1):
    c=i*d//(4*a)
    l=i*d-c*4*a
    if 2*a<=l and l<=3*a:
        print(3*a-l, a)
    elif a<=l and l<=2*a:
        print(a, 2*a-l)
    elif 3*a<=l:
        print(0, 4*a-l)
    else:
        print(l, 0)