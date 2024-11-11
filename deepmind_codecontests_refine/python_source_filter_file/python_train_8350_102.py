t =  int(input())

for _ in range(5):
    lista = list(map(int, input().split()))
    
    horas = 23 - lista[0]
    minutos = 60 - lista[1]
    qtd = minutos + (horas * 60)
    print(qtd)