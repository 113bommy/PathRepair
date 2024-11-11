import sys
input = sys.stdin.readline

Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    S = input() + "X"
    s = 0
    x = x1 = x2 = x3 = xx = 0
    for i in range(len(S)):
        if S[i] == "X":
            if s < b:
                pass
            elif a <= s < 2*b:
                x += 1
            elif a < 2*b and (3*a <= s < a+3*b-1 or 2*a <= s < a+2*b-1):
                xx += 1
            elif a < 2*b and 3*a <= s < a+4*b-1:
                x3 += 1
            elif a < 2*b and 2*a <= s < a+3*b-1:
                x2 += 1
            elif a <= s < a+2*b-1:
                x1 += 1
            else:
                # print("a, b, s =", a, b, s)
                print("NO")
                break
            s = 0
        else:
            s += 1
    else:
        # print("x, x1, x2, x3 =", x, x1, x2, x3)
        if x1+x2+x3 >= 2:
            print("NO")
        elif xx:
            print("YES")
        elif (x + x1 + x2*2 + x3*3) % 2 == 0:
            print("NO")
        else:
            print("YES")
