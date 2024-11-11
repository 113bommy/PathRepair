import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m,k = map(int,input().split())
    if n == 1:
        if m%2 == 1:
            sys.stdout.write("NO\n")

        else:
            val = m//2
            if val == k:
                sys.stdout.write("YES\n")

            else:
                sys.stdout.write("NO\n")

        continue

    if m == 1:
        if m % 2 == 1 or k > 0:
            sys.stdout.write("NO\n")

        else:
            sys.stdout.write("YES\n")

        continue

    if n%2 == 0 and m%2 == 0:
        if k%2 == 0:
            sys.stdout.write("YES\n")

        else:
            sys.stdout.write("NO\n")

        continue

    if n % 2 == 0 and m % 2 == 1:
        if ((n*m)-n) < k*2:
            sys.stdout.write("NO\n")

        else:
            if k % 2 == 0:
                sys.stdout.write("YES\n")

            else:
                sys.stdout.write("NO\n")

        continue

    if n % 2 == 1 and m % 2 == 0:
        if k*2 < m:
            sys.stdout.write("NO\n")

        else:
            if ((n * m) - m) < (k * 2)-m:
                sys.stdout.write("NO\n")

            else:
                val = ((k*2)-m)//2
                if val%2 == 1:
                    sys.stdout.write("NO\n")

                else:
                    sys.stdout.write("YES\n")


        continue

    sys.stdout.write("NO\n")