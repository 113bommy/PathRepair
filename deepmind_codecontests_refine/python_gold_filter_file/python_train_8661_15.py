# cook your dish here
t=int(input())
for i in range(t):
    flag=0
    s=list(map(int,input()))
    n=sum(s)
    if(n!=0):
        for i in s:
            if(i%2==0):
                flag+=1
        if(flag>=2 and 0 in s):
            if(n%3==0):
                print("red")
                continue
        print("cyan")    
    else:
        print("red")