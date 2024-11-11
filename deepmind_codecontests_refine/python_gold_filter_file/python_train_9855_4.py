string=input()
 
l=len(string)
if l%2!=0:
    print('4'*((l+1)//2)+'7'*((l+1)//2))
    exit()
n=l//2
worst='7'*n+'4'*n
if worst<string:
    print('4'*(n+1)+'7'*(n+1))
    exit()
 
newstr='4'*n+'7'*n
from itertools import permutations as pmt
List=pmt(newstr)
for x in List:
    result=''.join(x)
    if result>=string:
        print(result)
        exit()