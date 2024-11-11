n=int(input())
oddup=0
odddown=0
posswap=0
for i in range(n):
    up,down=map(int,input().split())
    if(up%2!=down%2):
        posswap+=1
    if(up%2!=0):
        oddup+=1
    if(down%2!=0):
        odddown+=1
if(oddup%2==0 and odddown%2==0):
    print("0")
elif(oddup%2==1 and odddown%2==1 and posswap>=1 and n>1):
    print("1")
else:
    if(n==1):
        if(oddup==0 and odddown==0):
            print("0")
        else:
            print("-1")
    else:
        print("-1")
