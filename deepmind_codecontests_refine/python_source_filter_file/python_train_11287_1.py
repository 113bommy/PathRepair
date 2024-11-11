n = int(input())


cards = list(map(int, input().split()))
cards.sort()

if n == 1:
    print(-1)
    exit()

if n == 2:
    middle = (cards[1] - cards[0]) // 2
    if (cards[1] -cards[0]) % 2 or cards[1] - cards[0] == 0:
        pass
    else:
        print(3)
        print(cards[0] -2*cards[1], (cards[0] + cards[1])//2, 2*cards[1] - cards[0])
        exit()

b = sorted([cards[i] - cards[i-1] for i in range(1, n)])

if len(set(b)) == 1:
    if b[0] != 0:
        print(2)
        print(cards[0]-b[0],cards[-1]+b[0])
    
    else:
        print(1)
        print(cards[0])

elif len(set(b)) > 2 or b[-1] != 2 * b[-2]:
    print(0)

else:
    print(1)
    for i in range(1,n):
        if cards[i] - cards[i-1] != b[0]:
            print(cards[i-1]+b[0])