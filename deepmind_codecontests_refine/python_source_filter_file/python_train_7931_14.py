q = int(input())
for i in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    t = 0
    for j in range(1,n,2):
        if int(b[j]) - int(b[j-1]) == 1:
            t += 1
            break
    if t == 0:
        print(1)
    else:
        print(2)