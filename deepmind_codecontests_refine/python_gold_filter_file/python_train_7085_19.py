while True:
  cards = str(input())
  if cards == '-':
    break
  
  n = int(input())
  for i in range(n):
    p = int(input())
    cards = cards[p:] + cards[:p]
  print(cards)
