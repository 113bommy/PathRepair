def chast(x):
    x = str(x)
    y = '0'
    for i in range(len(x)):
        if x[i] == '4' or x[i] == '7':
            y += x[i]
    return(int(y))
    
a,b = map(int, input().split())    
c = a+1


while chast(c) != b:
    c += 1
    
print(c)