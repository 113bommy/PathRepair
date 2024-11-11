# bsdk idhar kya dekhne ko aaya hai, khud kr!!!
# import math
# from itertools import *
# import random
# import calendar
import datetime
# import webbrowser

hundred_coin, ten_coin = map(int, input().split())
won = 0
for i in range(0, 10000000):
    if i % 2 == 0:
        ciel_money = 0
        # wrote code for ciel
        if hundred_coin >= 2:
            hundred_coin -= 2
            ciel_money += 2 * 100
            if ten_coin >= 2:
                ciel_money += 2*10
                ten_coin -= 2
            else:
                won = "Hanako"
                break
        else:
            if hundred_coin == 1:
                hundred_coin = 0
                ciel_money += 100
                if ten_coin >= 12:
                    ciel_money += 120
                    ten_coin -= 12
                elif ten_coin >= 11:
                    ciel_money += 110
                    ten_coin -= 11
                else:
                    won = "Hanako"
                    break
            else:
                if ten_coin >= 22:
                    ciel_money += 220
                    ten_coin -= 22
                else:
                    won = "Hanako"
                    break
        if ciel_money == 220:
            continue
        else:
            won = "Hanako"
            break
    elif i % 2 != 0:
        hanako_money = 0
        # now for hanako
        if ten_coin >= 22:
            hanako_money += 220
            ten_coin -= 22
        elif ten_coin >= 12:
            hanako_money += 120
            ten_coin -= 12
            if hundred_coin > 0:
                hanako_money += 100
                hundred_coin -= 1
            else:
                won = "Ciel"
                break
        elif ten_coin >= 2:
            hanako_money += 20
            ten_coin -= 2
            if hundred_coin >= 2:
                hanako_money += 200
                hundred_coin -= 2
            elif hundred_coin == 1:
                hanako_money += 100
                hundred_coin -= 1
            else:
                won = "Ciel"
                break
        else:
            won = "Ciel"
            break
        if hanako_money == 220:
            continue
        else:
            won = "Ciel"
            break
print(won)
