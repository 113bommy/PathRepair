def orange(n):
    percent = 0
    lista = []
    lista = list(map(int,input().split()))
    for i in range(0,n):
        percent = percent + lista[i]
    print(percent/n)

x = int(input())
orange(x)
    
    