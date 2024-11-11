Piles= {}
Piles[100], Piles[10] = [int(x) for x in input().split()]
while True:
    #Ceil's Turn, wins if she gets 220 coins
    SumOfYens = min(2, Piles[100]) * 100
    Piles[100] -= min(2, Piles[100])
    if (220 - SumOfYens)/10 <= Piles[10]: Piles[10] -= (220 - SumOfYens)/10
    else: print("Hanako"); break
    #Hanako's Turn
    if Piles[10] >= 22: Piles[10] -= 22
    elif Piles[10] >= 12 and Piles[100] >= 1: Piles[10] -= 12; Piles[100] -= 1
    elif Piles[10] >= 2 and Piles [100] >= 2: Piles[10] -= 2; Piles[100] -= 2
    else: print("Ciel"); break
