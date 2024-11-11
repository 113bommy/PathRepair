while True:
    n = int(input())
    if n == 0:
        break
    a = 0
    b = 0
    for i  in range(n):
        cardnum = [int(i) for i in input().split()]
        if cardnum[0] < cardnum[1]:
            b += sum(cardnum)
        elif cardnum[0] > cardnum[1]:
            a += sum(cardnum)
        else:
            a += cardnum[0]
            b += cardnum[1]
print(a,b)

