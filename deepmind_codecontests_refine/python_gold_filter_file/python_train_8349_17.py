p=int(input())
plusiki=0
while plusiki<p:
    h,m=input().split()
    h=int(h)
    m=int(m)
    #добавить сюда подсчёт сколько осталось до нового года
    h=23-h
    m=60-m
    print(h*60+m)
    plusiki=plusiki+1