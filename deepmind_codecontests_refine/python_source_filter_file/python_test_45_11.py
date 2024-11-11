import math

for _ in range(0,int(input())):
    n=int(input())
    days=input().split(" ")
    length=int(days[0])+1
    for i in range(1,n):
        if int(days[i]) == 0 and int(days[i-1])==0:
            length=-1
            break
        if int(days[i])==1 and int(days[i-1])==0:
            length=length+1
            
        if int(days[i])==1 and int(days[i-1])==1:
            length=length+5
        
        print(length)
    
    print(length)
