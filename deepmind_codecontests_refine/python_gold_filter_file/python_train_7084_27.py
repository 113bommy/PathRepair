while True:
    card = input()
    if card == '-': break
    for i in range(int(input())):
        a = int(input())
        card = card[a:] + card[:a]
    print(card)

