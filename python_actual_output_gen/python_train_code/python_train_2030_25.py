n = int(input())
x = str(input())
y = str(input())
n = 12
a =[]

x = [int(i) for i in str(x)] 
y = [int(i) for i in str(y)] 


for i in range(0,len(x)):
    if abs(x[i] - y[i]) < 5:
        a.append(abs(x[i] - y[i]))
    elif abs(x[i] - y[i]) == 6:
        a.append(4)
    elif abs(x[i] - y[i]) == 7:
        a.append(3)
    elif abs(x[i] - y[i]) == 8:
        a.append(2)
    elif abs(x[i] - y[i]) == 9:
        a.append(1)
                
print(sum(a))