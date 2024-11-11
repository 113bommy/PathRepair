def f(x):
    x+=1
    while x%10==0:
        x//=10
    return x

base=int(input())
compteur=1
liste=[]
while f(base) not in liste:
    liste.append(f(base))
    base=f(base)
    compteur+=1
print(compteur)