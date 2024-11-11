n=int(input())
if n<2 or n>50 or n%2 !=0:
    print("N should be positive int between 2 and 50")
else:    
    ticket=input()  
    
    if len(ticket) != n:
        print ("ticket number length should equal to n")
    else:    
        flag=True
        for e in range(0,n):
            if not (ticket[e]=="7" or ticket[e]=="4"):
                flag=False
        if not flag:
            print("NO")
        else:
            firstSum=0
            secondSum=0
            for ele in range(0, n//2):
                firstSum+=int(ticket[ele])
                secondSum+=int(ticket[ele+(n//2)])
            if(firstSum==secondSum):
                print("YES")
            else:
                print('NO')
  