def func():
    card = input()
    rank, suit = card[0], card[1]
    hand = input.split(' ')
    for c in hand:
        if rank in c or suit in c:
            print("YES")
            return
    print("NO")
    