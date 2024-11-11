tst = int(input())

for test in range(tst):
    k = int(input())
    n = input()
    a=b=-1
    if k == 1:
        print(-1, -1)
    else:
        for i in range(k-1):
            if n[i] != n[i+1]:
                a = i+1
                b = i+2
                break
        print(a, b)
