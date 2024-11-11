from sys import stdin

nbVilles,nbRoutes,nbMagasins=map(int,stdin.readline().split())
voisins=[[] for i in range(nbVilles+1)]
enAttente=[]
estMagasin=[False]*(nbVilles+1)
for route in range(nbRoutes):
    depart,arrive,prix=map(int,stdin.readline().split())
    voisins[depart].append([arrive,prix])
    voisins[arrive].append([depart,prix])

prixMin=1000*1000*1000+1
villeMin=-1
magasins=[]
if nbMagasins!=0:
    magasins=list(map(int,stdin.readline().split()))
    for magasin in magasins:
        estMagasin[magasin]=True

for magasin in magasins:
    for voisin,prix in voisins[magasin]:
        if not estMagasin[voisin] and prix<prixMin:
            prixMin=prix
            villeMin=voisin
if villeMin==-1:
    print(-1)
else:
    print(prixMin)
