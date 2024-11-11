lst = []
for t in range(int(input())):
    n = int(input())
    if n == 44:
        print("YES\n6 7 10 21")
    elif n == 36:
        print("YES\n5 6 10 15")
    elif n == 40:
        print("YES\n2 6 10 22")
    elif n > 30:
        print("YES\n6 10 14 " + str(n-30))
    else:
        print("NO")
