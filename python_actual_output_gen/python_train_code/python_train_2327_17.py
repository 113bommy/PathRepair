c=0
k=0
for _ in range(int(input())):
    a,b=map(int,input().split())
    if(a>b):
        c+=1
    elif(a<b):
        k+=1
if(c<k):
    print("Mishka")
elif(c==k):
    print("Friendship is magic!^^")
else:
    print("Chris")