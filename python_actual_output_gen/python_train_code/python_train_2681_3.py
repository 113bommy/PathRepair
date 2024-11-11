#for _ in range(int(input())):
    
n = int(input())
a = list(input())

ans = 0
x = a.count('(')
y = a.count(')')

if x!= y:
    print(-1)
else:
    c,f= 0,0
    start,time = 0,0
    for i in range(n):
        if a[i] == '(':
            c += 1
            f = 1
        else:
            c -= 1



        if f==1 and c==0:
            time += (i-start)+1
            start = i
            f= 0

        #if c<0 and f == 0:
            #start = i
            #f = 1

    print(time)
            
            



        

        
