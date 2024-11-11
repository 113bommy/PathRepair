input()
cards = input().split()
cards = [int(i) for i in cards]
s = 0
d = 0
while True:
    if not cards:
        break
    else:
        if len(cards) == 1:
            s += cards[0]
            cards.remove(cards[0])
            continue
        if cards[0] >= cards[-1]:
            s += cards[0]
            cards.remove(cards[0])
        elif cards[0] < cards[-1]:
            s += cards[-1]
            cards.remove(cards[-1])

        if cards[0] >= cards[-1]:
            d += cards[0]
            cards.remove(cards[0])
        elif cards[0] < cards[-1]:
            d += cards[-1]
            cards.remove(cards[-1])

print(s, d)
