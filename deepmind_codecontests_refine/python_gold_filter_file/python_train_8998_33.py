n = input()
if (int(n[-1]) % 2 == 1):
    print(0)
else:
    rem = 0
    if (len(n) <= 2):
        rem = int(n) % 4
    else:
        rem = int(n[-2:]) % 4
    ans = 2 ** rem
    print((2 * (1 + ans)) % 5)