_, x = [int(_) for _ in input().split()]
cards = [int(_) for _ in input().split()]

cards_sum = abs(sum(cards))
print(cards_sum // x + int(cards_sum % x != 0))