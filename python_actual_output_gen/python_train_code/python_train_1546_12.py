cislo = (input())
pocetnul = 0
jednicka = False

for i in range(1, len(cislo)-1, 1):
    if cislo[i] == "1":
            jednicka = True
    if jednicka == True:
        if cislo[i] == "0":
            pocetnul +=1
        if pocetnul == 6:
            print("yes")
            break



if pocetnul != 6:
    print("no")