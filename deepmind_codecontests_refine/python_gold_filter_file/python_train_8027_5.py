n,k = map(int,input().split())

s=[int(x) for x in input().split()]
sm =sum(s)
flag=1
if sm%k!=0:
    print('No')
    
else:
    vh=sm//k
    s1=[]
    acummu=0
    count=0
    for i in range(n):
        count+=1
        acummu+=s[i]
        if acummu>vh:
            print('No')
            flag=0
            break
        elif acummu<vh:
            continue
            
        elif acummu==vh:
            acummu=0
            s1.append(count)
            count=0
            
    if acummu!=0:
        s1.append((sm)//vh)
    if flag: 
        print("Yes")
        print(*s1)