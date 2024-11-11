cards = dict((x, list(input())) for x in 'abc')

turn = 'a'
while len(cards[turn]):
  turn = cards[turn].pop(0)
print(turn.upper())
