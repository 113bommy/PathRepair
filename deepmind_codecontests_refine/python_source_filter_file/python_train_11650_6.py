while True:
    x = int(input())
    if x == 0:
        break
    dcl = {}
    for i in range(x):
        inp = list(map(str, input().split()))
        dcl[inp[0]] = inp[1]
    ans = ""
    x = int(input())
    for i in range(x):
        y = str(input())
        if y in dcl:
            ans += dcl[y]
        else:
            ans += y
    print(ans)