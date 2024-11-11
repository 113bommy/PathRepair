import math # Joueur 1 Ashishgup
# Joueur 2 FastestFinger
def nb_facteurs(n, p):
    if n==0 or n<p:
        return 0
    nb = 0
    while n%p==0:
        nb += 1
        n = int(n/p)
    return nb

nb_cases = int(input())
while nb_cases > 0:
    nb_cases -= 1

    n = int(input())


    if n==1:
        print("FastestFinger")
        continue
    if n==2:
        print("Ashishgup")
        continue
    # Impair
    if n%2==1:
        print("Ashishgup")
        continue
    # 4 * 2^k * impair
    if n%4==0 and n>2**nb_facteurs(n,2):
        print("Ashishgup")
        continue

    # 2 * 2^k * impair1 * impair 2
    nb_facteur_impair = 0
    for x in range(2, int(math.sqrt(n/nb_facteurs(n,2))+2)):
        if x%2==1:
            nb_facteur_impair += nb_facteurs(n,x)
        if nb_facteur_impair >= 2:
            break
    if nb_facteur_impair >= 2:
        print("Ashishgup")
    else:
        print("FastestFinger")
