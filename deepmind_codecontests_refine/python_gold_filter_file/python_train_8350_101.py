t=int(input())
for i in range(t):
    x=list(map(int,input().split()))
    h=x[0]
    m=x[1]
    if h<24 and m<60:
        timeh=24-h
        timem=60-m
    if timeh==1:
        print(timem)
    elif timeh==24:
        print(23*60+timem)
    else:
        print((timeh-1)*60+timem)
