n = int(input())

kuro = input()
shiro = input()
katie = input()

words = [kuro, shiro, katie]

bank = [ [0 for i in range(0, ord("z")-ord("A")+1)] for j in range(0, 3) ]

for i in range(0, 3):

    for l in words[i]:
         bank[i][ord(l)-65] += 1

    ##if sum(bank[i]) == max(bank[i]):
        ##max(bank)-=1

    summ = sum(bank[i])

    if summ == max(bank[i]):
        for j in range(0, 52):
            if bank[i][j] == summ:
                bank[i][j]-=2
                break

kuro = min(len(words[0]), max(bank[0])+n)
shiro = min(len(words[1]), max(bank[1])+n)
katie = min(len(words[2]), max(bank[2])+n)

if kuro > shiro and kuro > katie:
    print("Kuro")

else:
    if shiro > kuro and shiro > katie:
        print("Shiro")

    else:
        if katie > kuro and katie > shiro:
            print("Katie")

        else:

            if katie == shiro or katie == kuro or shiro == kuro: ## AT LEAST TWO share ... :(
                print("Draw")
