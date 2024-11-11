n=int(input())
a=input()
zero=0
one=0
output = ""
for i in a:
    if(i=='z'):
        zero+=1
    elif(i=='n'):
        one+=1
for i in range (one):
    output += '1'
for i in range (zero):
    output += '0'
print(output)