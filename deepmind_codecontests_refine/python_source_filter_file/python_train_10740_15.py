q = int(input())
for _ in range(q):
    b,w = map(int,input().split())
    if b == w:
        print("YES")
        for i in range(b + w):
            print("1 " + str(i + 1))
    elif b > w:
        if b > 3 * w + 1:
            print("NO")
        else:
            print("YES")
            b -= (w + 1)
            for i in range(w * 2 + 1):
                print("2 " + str(i + 1))
            cnt = 2
            while b > 0:
                print("1 " + str(cnt))
                b -= 1
                if b == 0:
                    break
                print("3 " + str(cnt))
                b -= 1
                cnt += 2
    elif w > b:
        if w > 3 * b + 1:
            print("NO")
        else:
            print("YES")
            w -= (b + 1)
            for i in range(b * 2 + 1):
                print("3 " + str(i + 1))
            cnt = 2
            while w > 0:
                print("2 " + str(cnt))
                w -= 1
                if b == 0:
                    break
                print("4 " + str(cnt))
                w -= 1
                cnt += 2