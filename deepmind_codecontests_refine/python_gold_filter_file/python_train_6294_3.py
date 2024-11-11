coins_input = {
  "A": 0,
  "B": 0,
  "C": 0
}
for i in range(3):
    coin = input()
    if '<' in coin:
        sp = coin.split('<')
        coins_input[sp[1]] += 1
    else:
        sp = coin.split('>')
        coins_input[sp[0]] += 1
if (coins_input['A']== 1 and coins_input['B']==1 and coins_input['C']== 1):
    print("Impossible")
else:
   coins_sort =  dict(sorted(coins_input.items(), key=lambda item: item[1]))
   print(''.join(c for c in  coins_sort.keys() ))