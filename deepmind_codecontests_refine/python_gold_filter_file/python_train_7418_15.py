#Codeforces1388A
for i in range(int(input())):
    N = int(input())
    num = N
    if N == 40:
        print("YES\n", 6, 10, 15, 9)
    elif N == 44:
        print("YES\n", 6, 7, 10, 21)
    elif N == 36:
        print("YES\n", 5, 6, 10, 15)
    elif N > 30:
        print("YES\n", 6, 10, 14, N - 30)
    else:
        print("NO")
