def f():
    b = [a[0]]
    for e in a[1:]:
        if b != []:
            if e == b[-1] or abs(e-b[-1])%2==0:
                b.pop()

            else:
                b.append(e)
        else:
            b.append(e)

    for i in range(1,len(b)):
        if abs(b[i]-b[i-1])%2:
            print('NO')
            return

        print('YES')

n=int(input())
a=[int(i) for i in input().split()]


f()