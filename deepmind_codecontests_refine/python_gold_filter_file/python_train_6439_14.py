a,b=map(int,input().split())
if  a==b :
    print("Draw")
elif (b==1 or a<b) and a!=1:
    print("Bob")
else:
    print("Alice")