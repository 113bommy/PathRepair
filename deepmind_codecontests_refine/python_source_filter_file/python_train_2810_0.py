while True:
    a = list(map(str, input().split()))
    if a[0] == "0":
        break
    elif int(a[1]) <= 30:
        print(" ".join(a))
    elif int(a[1]) == 31 and int(a[2]) <= 4:
        print(" ".join(a))
    else:
        a[0] = "?"
        s = int(a[1])
        s -= 30
        a[1] = str(s)
        print(" ".join(a))
