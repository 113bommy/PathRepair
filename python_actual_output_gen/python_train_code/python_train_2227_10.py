a,b=map(int,input().split())
if  a==b :
    print("Draw")
elif b==1 or a<b or a!=1 :
    print("Bob")
else:
    print("Alice")