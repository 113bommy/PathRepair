for i in range(int(input())):
    b,w = map(int, input().split())
    if b > 3*w + 1 or w > 3*b + 1:
        print("NO")
    else:
        print("YES")
        if b <= w:
            for c in range(1, 2*b+1):
                print(c, 3)
            if w-b > 0:
                print(2*b+1, 3)
                j = w+1-b
                while j > 0:
                    if j > b:
                        print(2*(j-b), 2)
                    if j <= b:
                        print(2*j, 4)
                    j -= 1
        else:
            for c in range(1, 2*w+1):
                print(c, 2)
            if b-w > 0:
                print(2*w+1, 2)
                j = b+1-w
                while j > 0:
                    if j > w:
                        print(2*(j-w), 1)
                    if j <= b:
                        print(2*j, 3)
                    j -= 1