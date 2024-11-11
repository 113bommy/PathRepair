# import sys
import math
# sys.stdin = open('input1.txt', 'r') 
# sys.stdout = open('output1.txt', 'w')
t,x_i,y_i,x_f,y_f=input().split(" ")
command=input()
t=int(t)
x_i=int(x_i)
y_i=int(y_i)
x_f=int(x_f)
y_f=int(y_f)
v=y_f-y_i
h=x_f-x_i
coor=int(0)
if v > 0 :
    for i  in range(0,len(command)) :
        if command[i] == 'N' and v > 0:
            v-=1
            coor=max(i,coor)
    if h > 0 :
        for i in  range(0,len(command )) :
            if command[i] == 'E' and  h > 0 :
                h-=1
                coor=max(i,coor)
    elif h < 0 :
        for i in  range(0,len(command )) :
            if command[i] == 'W' and  h < 0 :
                h+=1
                coor=max(i,coor)
    if h==0 and v==0 :
        print(coor+1)
    else :
        print("-1")
else :
    for i  in range(0,len(command)) :
        if command[i] == 'N' and v > 0:
            v+=1
            coor=max(i,coor)
    if h > 0 :
        for i in  range(0,len(command )) :
            if command[i] == 'E' and  h > 0 :
                h-=1
                coor=max(i,coor)
    elif h < 0 :
        for i in  range(0,len(command )) :
            if command[i] == 'W' and  h < 0 :
                h+=1
                coor=max(i,coor)
    if h==0 and v==0 :
        print(coor+1)
    else :
        print("-1")









            
            
        






    

        






    





