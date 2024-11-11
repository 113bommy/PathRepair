while True:
    try:
        a, b, c = map(int, input().split())
    except:
        break
    l=[True] * 11
    l[a] = l[b] = l[c] = False
    sum = a + b
    over = 0

    fpr i in range(1,11):
        if l[i]:
            if sum + i >= 20:
                over += 1

    if over / 7 < 0.5:
        print("YES")
    else:
        print("NO")