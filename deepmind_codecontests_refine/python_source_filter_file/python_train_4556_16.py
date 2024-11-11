#Author : Zahin uddin
#Github : https://github.com/Zahin52


from sys import *
from statistics import mean
import math
#import queue
input=stdin.readline
listInput=lambda:list(map(int,input().strip().split()))
lineInput= lambda:map(int,input().strip().split())
sJoin=lambda a,sep : f'{sep}'.join(a)
arrJoin=lambda a,sep : f'{sep}'.join(map(str,a))
#print=stdout.write
def isPrime(n):
    if(n <= 1):
        return False
    if(n <= 3):
        return True
    if(n % 2 == 0 or n % 3 == 0):
        return False
    for i in range(5,int(math.sqrt(n) + 1), 6):
        if(n % i == 0 or n % (i + 2) == 0):
            return False
    return True
def main():
    c=0
    n=int(input())
    arr=sorted(listInput())
    # a=listInput()
    #print(len(a))
    # print(round(4.449,1)
    # if 4.5<=mean(arr)<=5:
    #     print(0)
    #     return
    for i in range(n):        
        if 4.5<=mean(arr)<=5 :
            print(c)
            return
        else:
            arr[i]=5
            c+=1
           
    
if __name__ == "__main__":
    main()
