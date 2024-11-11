from collections import Counter
import string
import math
import sys
def array_int():
    return [int(i) for i in sys.stdin.readline().split()]
def vary(arrber_of_variables):
    if arrber_of_variables==1:
        return int(sys.stdin.readline())
    if arrber_of_variables>=2:
        return map(int,sys.stdin.readline().split()) 
def makedict(var):
    return dict(Counter(var))
# i am noob wanted to be better and trying hard for that
def printDivisors(n) : 
    divisors=[]  
    # Note that this loop runs till square root 
    i = 1
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
              
            # If divisors are equal, print only one 
            if (n//i == i) : 
                divisors.append(i) 
            else : 
                # Otherwise print both 
                divisors.extend((i,n//i)) 
        i = i + 1
    return divisors
n=vary(1)
num1=array_int()
fn=num1[0]
fcn=num1[1:]
num1=array_int()
sn=num1[0]
scn=num1[1:]
count=0
i=n*n
# print(fcn,scn)
while i:
    if len(fcn)==0:
        print(count,2)
        break
    if len(scn)==0:
        print(count,1)
        break
    if fcn[0]>scn[0]:
        fcn.extend((scn[0],fcn[0]))
        fcn.pop(0)
        scn.pop(0)
        count+=1
    elif scn[0]>fcn[0]:
        scn.extend((fcn[0],scn[0]))
        scn.pop(0)
        fcn.pop(0)
        count+=1
    i-=1
else:
    print(-1)




    

    



    


    














        

    

            
    





        
        
   
