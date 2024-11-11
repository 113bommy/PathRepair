_ = 1
_ = int(input())
while _ > 0:
    _ -= 1

    n = int(input())
    s = input()
    a, b = 0, 0
    for x in range(n-1):
        if (s[x] == 'a' and s[x+1] == 'b') or (s[x] == 'b' and s[x+1] == 'a'):
            print(x+1, x+2)
            break
    else:
        print("-1 -1")
