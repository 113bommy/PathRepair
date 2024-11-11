
n= int(input())
a= input()

count= 0
time= 0

for element in a:

    if(element== '('):
        count+= 1
    elif(element== ')'):
        count-= 1

        if(count<= 0):
            time+= 2

if(count!= 0):
    print(-1)
else:
    print(time)


                
            
