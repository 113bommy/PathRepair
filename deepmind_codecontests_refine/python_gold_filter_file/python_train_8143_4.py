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
mod=1000003
#i am noob wanted to be better and trying hard for that
s=input()

ans=''
for i in s:
    if i=='>':
        ans+='1000'
    if i=='<':
        ans+='1001'
    if i=='+':
        ans+='1010'
    if i=='-':
        ans+='1011'
    if i=='.':
        ans+='1100'
    if i=='[':
        ans+='1110'
    if i==',':
        ans+='1101'
    if i==']':
        ans+='1111'
# print(ans)
print(int(ans,2)%mod)





        







    


            
        


        

   





    
        






    


            


        

        
        




    











            
        


        






                 

            
    

















        






        


        



