n, k, s = map(int, input().split())
if (n - 1) * k < s or k > s:
    print("NO")
else:
    if n == 2:
        print("YES")
        for i in range(s):
            if i % 2 == 0:
                print(2, end=' ')
            else:
                print(1, end=' ')
    else:
        print("YES")
        full = (s - k) // (n - 2)
        ost = s - full * (n - 1)
        last = 1
        for i in range(full):
            if i % 2 == 0:
                print(n, end=' ')
                last = n
            else:
                print(1, end=' ')
                last = 1
        k -= full
        s -= full * (n - 1)
        if last == 1:
            i = 0
            while k > 1:
                k -= 1
                if i % 2 == 0:
                    print(2, end=' ')
                    last = 2
                else:
                    print(1, end=' ')
                    last = 1
                i += 1
                ost -= 1
            print(ost + last if ost != 0 else "", end=' ')
        else:
            i = 0
            while k > 1:
                k -= 1
                ost -= 1
                if i % 2 == 0:
                    print(n - 1, end=' ')
                    last = n - 1
                else:
                    print(n, end=' ')
                    last = n
                i += 1
            print(last - ost if ost != 0 else "", end=' ')