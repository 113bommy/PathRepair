n, k, l, c, d, p, nl, np = list(map(int, input().split()))

drinkInLitre = k * l
toastOfDrinkPossible = drinkInLitre // nl

toastOfLimePossible = c * d
toastOfSaltPossible = p // np

ans = min(toastOfLimePossible // n, min(toastOfSaltPossible//n, toastOfDrinkPossible//n))
print(ans)
