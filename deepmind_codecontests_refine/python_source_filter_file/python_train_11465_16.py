for _ in " "*int(input()):
    c=int(input())
    k=(c+(((c**2)-4*c)**0.5))/2
    try:print('Y',round(k,6),round(c-k,6))
    except:print('N')