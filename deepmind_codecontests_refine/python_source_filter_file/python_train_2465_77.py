#import sys
#import math
#sys.stdout=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/output.txt","w")
#sys.stdin=open("C:/Users/pipal/OneDrive/Desktop/VS code/python/input.txt","r")
#t=int(input())
#for i in range(t):
n=int(input())
l=list(map(int,input().split()))
if n==1:
    print([0])
elif n==2:
    print(min(l))
else:
    l.sort()
    if n%2==0:
        print(l[n//2])

    else:
        print(l[n//2])
    




    
    

    
    


    
    
    