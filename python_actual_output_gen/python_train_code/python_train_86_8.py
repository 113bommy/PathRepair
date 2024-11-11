t = int(input())

for i in range(t):
    n = int(input())
    last = 0, 0
    done = False
    for _ in range(n):
        p, c = [int(i) for i in input().split()]
        if (p < c or (p == last[0] and c != last[1])) and not done:
            print("NO")
            done = True
        if (p != last[0] or c != last[1]) and not done:
            if p < last[0] or c < last[1]:
                print("NO")
                done = True
        if ((p > last[0] > last[1]) and (p-last[0]) <= (c-last[1])) and not done:
            print("NO")
            done = True
        last = p, c
    else:
        if not done:
            print("yes")
    """
    print("token:", i+1)
    if i+1 == 23:
        print("start input print:")
        print(last)
        print(p, c)
        print("stop input print")
    """
