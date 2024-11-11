n=int(input())
for i in range(1,40):
    if(i*(i+1)//2==n):
        print(i)
        print(*[j for j in range(1,i+1)])  
        break
    elif(i*(i+1)//2>n):
        print(i-1)
        print(*[j for j in range(1,i-1)],n-(i-2)*(i-1)//2)    
        break