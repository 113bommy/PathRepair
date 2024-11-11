#----Kuzlyaev-Nikita-Codeforces-----
#------------03.04.2020-------------

alph="abcdefghijklmnopqrstuvwxyz"

#-----------------------------------

n=int(input())
if n<=11:print(0)
elif n<=19:print(4)
elif n==20:print(15)
elif n==21:print(4)
else:
    print(0)