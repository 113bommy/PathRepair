c=0
b=0
for _ in range(int(input())):
    a,b=map(int,input().split())
    if(a>b):
        c+=1
    elif(a<b):
        b+=1
if(c>b):
    print("Mishka")
elif(c==b):
    print("Friendship is magic!^^")
else:
    print("Chris")