a=int(input())
for i in range (a):
    mas = [int(i) for i in input().split()]
    m=(mas[0]+mas[1])/(mas[2]+mas[3])   
    if m%1==0:
        print(int(m))
    else:
        print(-1)
