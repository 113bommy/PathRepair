amount = int(input())
samount = str(amount)
if (amount < 0 and len(samount) > 2):

    if (samount[-1] < samount[-2]):
        newAmount = samount[0:-2] + samount[-1]
    else:
        newAmount = samount[0:-1]
    print(newAmount)
else:
    print(amount)
