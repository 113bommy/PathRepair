n1,n2 = map(int,input().split())
k = {}
checking = False
for j in range(n1+1,n2):
    k = {}
    check = False
    for i in str(j): 
        try :
            if k[str(i)] == 0:
                check = True
                break
        except KeyError:
            k[str(i)] = 0
        
    if check == False:
        checking = True
        print(j)
        break

if checking == False:
    print(-1)
