n = int(input())

for x in range(n//7,0,-1):
    if (n-x*7)%4 == 0:
        print ('4'*((n-x*7)//4 )+ '7'*x)
        break
else:
    print (-1)