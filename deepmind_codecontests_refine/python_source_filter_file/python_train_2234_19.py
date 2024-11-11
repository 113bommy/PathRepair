def main():
    x = [int(y) for y in input().split()]
    n = x[0]
    m = x[1]
    suma = 0
    res = []
    while(suma<=n):
        suma+=2
        res.append(2)
    a = len(res)
    while(suma>n):
        res.pop()
        if(suma-1==n):
            suma-=1
            break;
        res.append(1)
        suma-=1
    sum = 0
    for i in range(len(res)):
        sum+=res[i]
    while(len(res)%m!=0 and a != 0):
        a-=1
        res.pop()
        res.append(1)
        res.append(1)
    if(a==0):
        print(-1)
    else:
        print(len(res))
main()