import bisect
while True:
    n = int(input())
    if n == 0:
        break
    card_set = [sorted(int(input()) for _ in range(n)), []]
    card_set[1] = sorted({i for i in range(1, 2*n+1)}.difference(card_set[0]))
    card = turn = 0
    flag = 1
    ba = []
    while flag:
        if len(ba) == 0:
            card = card_set[turn].pop(0)
            ba.append(card)
            flag = 0 if len(card_set[turn])==0 else 1
            turn = 0 if turn else 1
            continue
        last_card = ba[-1]
        x = bisect.bisect_left(card_set[turn], last_card)
        try:
            card = card_set[turn].pop(x)
            ba.append(card)
        except IndexError:
            ba = []
        flag = 0 if len(card_set[turn])==0 else 1
        turn = 0 if turn else 1
    print(*[len(cet) for cet in card_set], sep='\n')