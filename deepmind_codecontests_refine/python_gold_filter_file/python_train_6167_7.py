def solve(n, x):
    a = ""
    b = ""
    turn = True
    for i in x:
        if turn:
            if i == "2":
                a += "1"
                b += "1"
            elif i == "0":
                a += "0"
                b += "0"
            else:
                a += "1"
                b += "0"
                turn = False
        else:
            a += "0"
            b += i
    print(a)
    print(b)

t = int(input())
while t != 0:
    n = int(input())
    x = input()
    solve(n, x)
    t -= 1
