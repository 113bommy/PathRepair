card = [int(i) for i in input().split()]
card.sort()
c = 0
mas = [0]*5

for i in range(5):
    if card.count(card[i]) == 2: 
        mas[i] = card[i]*2
    if card.count(card[i]) == 3: 
        mas[i] = card[i]*3

for i in card:                     ## вся сумма
    c += i 

print(c - max(mas))