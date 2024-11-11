while True:
    try:
        a, b, n = map(int, input().split())
    except:
        break

    s = str(a/b)
    sum = 0
    x = s.index(".")+1
    for i in s[x:2+x]:
        sum += int(i)

    print(sum)