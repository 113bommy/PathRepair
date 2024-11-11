from itertools import product
s=input()
for b in list(product(["+","-"],repeat=3)):
    ans=s[0]+b[0]+s[1]+b[1]+s[2]+b[2]+s[3]
    if eval(ans)==7:
        print(ans+"=7")
        break
