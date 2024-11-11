n = int(input())
z=[]
for i in range(n):
    s = str(input())
    s=list(s)

    
    i=len(s)-1
    while int(s[i]) == 0:
            s[i] = '-1'
            i-=1
    i=0
    while int(s[i]) == 0:
            s[i] = '-1'
            i+=1
    
    x = 0
    for i in range (len(s)-1):
        if int(s[i]) == 0:
            x += 1
            
    z.append(x)
    
for i in range(len(z)-1):
    print(z[i])