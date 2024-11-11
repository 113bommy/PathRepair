x = int(input())
while x != 0:
    x = x - 1
    t = int(input())
    num = t >> 1
    if num & 1:
        print("NO")
    else:
        print("YES")
        st = 2
        evens = []
        odds = []
        while num > 0:
            num = num - 2
            evens.append(st)
            odds.append(st + 1)
            evens.append(st + 2)
            odds.append(st + 3)
            st += 4
        for i in evens:
            print(i, end = " ")
        for i in odds:
            print(i, end = " ")
        print()
