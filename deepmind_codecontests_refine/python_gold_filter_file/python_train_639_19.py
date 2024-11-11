n, m, k = [int(i) for i in input().split()]

liste_p = [int(i)-1 for i in input().split()]

nombre_etape = 0
indice_courant = 0 #on vire jusqu'au indice_courant+k

indice_liste_p = 0

while indice_liste_p < len(liste_p) :
	nombre_etape += 1
	#Nouveau tour de suppression
	#Si il était à la pos x on virerait de x-x%k à x-x%k+k
	x = liste_p[indice_liste_p] - indice_liste_p
	debut = x-x%k
	fin = debut+k
	tmp = indice_liste_p
	while indice_liste_p < len(liste_p) and liste_p[indice_liste_p]-tmp < fin :
		indice_liste_p += 1

print(nombre_etape)
