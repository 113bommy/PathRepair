n , x , y =   map(int,input().split())
lst = [int(x) for x in input().split()]
if x > y :
    print(n)
else:
    c = sum(map(lambda i: i <= y, lst));
    

    if(c%2==0):
        print(c//2)
    else:
        print((c//2) + 1)