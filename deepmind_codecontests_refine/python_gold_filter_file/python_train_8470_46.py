from collections import deque
import math
n = int(input())
#print(n//1000)
#print((n%1000)//100)
#print((n%100)//10)
#print(n%10)
while(True):
    n+=1
    if (n//1000)!=((n%1000)//100) and (n//1000)!=(n%100)//10 and (n//1000)!=(n%10):
       if ((n%1000)//100)!=(n%100)//10 and ((n%1000)//100)!=(n%10):
            if ((n%100)//10)!=(n%10):
                print(n)
                break;


