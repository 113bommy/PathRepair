n,m= (int(x) for x in input().split())
if min(n,m)%2==0: #choisir le minimun des deux valeurs puis faire le modulo
    #de ce minimun,sil est =0 alors il est paire et c'est malika qui gagne
    #sil est impaire alors c'es akshat qui gagne
    print("Malvika")
else:
    print("Akshat")
