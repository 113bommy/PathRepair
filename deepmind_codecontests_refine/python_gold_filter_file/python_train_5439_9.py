t=int(input())
for _ in range(t):
    n=int(input())
    num1=[]
    num=list(str(n))
    num.reverse()
    for i in range(len(num)):
      if(int(num[i])*(10**i)!=0):
        num1.append(int(num[i])*(10**i))
    
    num1.reverse()
    print(len(num1))
    print(*num1,sep=" ")
        