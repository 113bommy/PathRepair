n  = int(input())
for i in range(n):
    x =  input()
    if len(x) == 4 :
        print(int(x[0]) * 10)
    elif len(x) == 3 :
        print((int(x[0])-1 ) * 10 +6 )
    elif  len(x) == 2:
        print((int(x[0])-1 ) * 10 +3)
    else   :
        print((int(x[0])-1)*10 +1 )