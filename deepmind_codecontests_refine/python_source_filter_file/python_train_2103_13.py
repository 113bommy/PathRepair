t =int(input())
while t>0:
    a,b,c,d,k= map(int, input().split(' '))
    if(a%c==0):
        pen_number = a//c
    else:
        pen_number = a//c+1
    if(b%d==0):
        pencil_number = b//d
    else:
        pencil_number = b//d+1
    if(pen_number+pencil_number == k):
        print(-1)
    else:
        print("{0} {1}".format(pen_number, pencil_number))
    t-=1