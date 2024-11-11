t=int(input())

for n in range(1,t+1):
    list=[]

for n in range(1,t+1):
    a,b,x,y = input().split()
    x=int(x)
    y=int(y)
    a=int(a)
    b=int(b)  
    list.append(max(x*b, (a-x-1)*b, a*(y), a*(b-y-1)))

for n in list:
    print(n) 
