pontos = int(input())
x = []
y = []
cont = 0

for i in range(pontos+1):
    ponto = input().split(' ')
    
    x.append(int(ponto[0]))
    y.append(int(ponto[1]))

for i in range(1, pontos-1):
    if (x[i-1] < x[i]) and (y[i] < y[i+1]): cont += 1 # LESTE -> NORTE
    elif (y[i-1] < y[i]) and (x[i] > x[i+1]): cont += 1 # NORTE -> OESTE
    elif (x[i-1] > x[i]) and (y[i] > y[i+1]): cont += 1 # OESTE -> SUL
    elif (y[i-1] > y[i]) and (x[i] < x[i+1]): cont += 1 # SUL -> LESTE

print(cont)