# @author Matheus Alves dos Santos

from collections import defaultdict

flips_needed = defaultdict(lambda: 0, {
    'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1,
    '0': 1, '2': 1, '4': 1, '6': 1, '8': 1,
})

card_values = input()
flips = 0

for v in card_values:
    flips += flips_needed[v]
    
print(flips)
