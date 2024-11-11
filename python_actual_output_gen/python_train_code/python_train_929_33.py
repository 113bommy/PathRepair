n, h= map(int, input().split())
hi = input(":").split()
w = 0
for i in hi :
    if int(i) <= h:
        w = w+ 1
    elif int(i) > h :
        w = w+2
    else :
        pass
print(int(w))

        
        

          
