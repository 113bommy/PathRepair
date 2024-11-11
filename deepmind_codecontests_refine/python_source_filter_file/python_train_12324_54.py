t=int(input())
value = 0
for i in range(t):
    te =value
    x=input()
    if x == 'x++':
        value+=1
    elif x=='x--':
        value-=1
    elif x=='--x':
        value-=1
    elif x=='++x':
        value+=1

print(value)
        
        
        