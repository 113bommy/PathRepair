from copy import *
from math import *

def multiplyList(myList) : 
      
    # Multiply elements one by one 
    result = 1
    for x in myList: 
         result = result * x  
    return result



# t=int(input())
# for i in range(t):
n=int(input())
print(7+((n-1)*3))
# print(0,0)
# print(1,0)
# print(0,1)
# print(1,1)
# print(2,1)
l=[[0,0],[1,0],[0,1],[1,1],[2,1]]
for i in range(n):
    a=i+1
    b=a+1
    c=b+1
    l.append([a,b])
    l.append([b,b])
    l.append([c,b])
for i in range(len(l)):
    print(l[i][0],l[i][1])
