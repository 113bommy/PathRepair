n=input()
x=y=z=0
for i in range (0,len(n),2):
    if n[i]== '1':
        x+=1
    elif n[i]== '2':
        y+=1
    else:
        z+=1
m = "1+"*x + "2+" *y + "3+"*x
print (m[:-1])