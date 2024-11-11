n = int(input())
if n < 4: print("NO")
else:
    print("YES")
    while n > 5:
        a = str(n+1)
        b = str(n)
        print(a + " - " + b + " = 1 ")
        print("1 * 1 = 1")
        n -= 2
    if n == 4: print("4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24")
    else: print("5 - 2 = 3\n3 - 1 = 2\n2 * 3 = 6\n6 * 4 = 24")
