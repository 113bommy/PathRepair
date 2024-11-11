tests = input()
tests = int(tests)
for p in range(tests):
    a = input().split(' ')

    n = int(a[0])
    d = int(a[1])
    c = False
    if n != d:
        for i in range(1,n):
            r = i + (-(-d // (i+1)))
            #print(r)
            if r <= n:
                print('YES')
                c = True
                break
        if not c:
            print('NO')
    else:
        print('YES')





