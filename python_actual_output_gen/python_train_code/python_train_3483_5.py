
t = int(input())

for _ in range(t):
    
    a,b = map(int,input().split())
    s = b-a
    if(s>0 and s%2==1):
        print(1)
    elif(s==0):
        print(0)
    elif(s>0 and s%2==0):
        print(s)
    elif(s<0 and s%2==1):
        print(2)
    elif(s<0 and s%2==0):
        print(1)    