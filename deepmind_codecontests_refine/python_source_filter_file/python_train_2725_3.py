for _ in range(int(input())):
    n = int(input())
    a = list(map(int, list(input())))
    q1, min1 = n, float('inf')
    for q in range(n-1, -1, -1):
        if a[q] > min1:
            q1 = q
        else:
            min1 = q
    if q1 == n:
        print('1'*n)
    else:
        s, last = [1]*q1, a[q1]
        s.append(2)
        d1, d2 = a[:q1], [a[q1]]
        for q in range(q1+1, n):
            if a[q] >= last:
                s.append(2)
                d2.append(a[q])
                last = a[q]
            else:
                s.append(1)
                d1.append(a[q])
        d1 += d2
        for q in range(1, n):
            if d1[q] < d1[q-1]:
                print('-')
                break
        else:
            print(''.join(list(map(str, s))))
