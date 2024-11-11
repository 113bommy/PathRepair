n,b,d=map(int,input().split())
counter=0
juiceInjar=0
inputs=list(input().split())

for i in range(n):
    inputs[i]=int(inputs[i])

for i in inputs:
    if(i<=b):
        juiceInjar+=i
        if(juiceInjar>d):
            counter+=1 
            juiceInjar=0
print(counter)