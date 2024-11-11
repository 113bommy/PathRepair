N = int(input())
cards = ["{0} {1}".format(type, order) for type in ('S', 'H', 'C', 'D') for order in range(1,14)]
for i in range(N):
    card = input()
    cards.remove(card)
for rest in cards
    print(rest)