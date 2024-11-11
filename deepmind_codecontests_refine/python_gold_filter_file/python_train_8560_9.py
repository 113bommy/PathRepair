t=int(input())
for i in range (t):
    x,n,m= map(int,input().split())
    if x<=10 and m>0:
        print("YES")
    else:
        for i in range (n):
            x=x//2+10
        for i in range (m):
            x-=10
        
        if x>0: 
            print ("NO")
        else:
            print ("YES")