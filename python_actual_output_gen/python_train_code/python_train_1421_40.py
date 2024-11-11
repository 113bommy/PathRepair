a,b,c,d=map(int,input().split(" "))
n=max(3*a//10,a-a*c//250)
m=max(3*b//10,b-b*d//250)
if(n==m):
    print("Tie")
elif(n>m):
    print("Vasya")
else:
    print("Misha")