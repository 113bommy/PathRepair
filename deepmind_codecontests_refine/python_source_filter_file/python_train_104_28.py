n = int(input())
cards = {} #空の辞書
for i in range(n):
    card = input()
    cards[card] = 1
    
#print(cards)

for c in ['S', 'H', 'C', 'D']:
    for n in range(1,14):
        card = c + ' ' + str(n)
        if not key in cards:
            print(key)
