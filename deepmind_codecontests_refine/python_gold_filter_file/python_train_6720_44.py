n=int(input())
mi=0
ch=0
for i in range(n):
    x,y=map(int,input().split())
    
    if x > y:
        mi+=1
    if y > x:
        ch+=1
if mi==ch:
    print("Friendship is magic!^^")
elif mi>ch:
    print("Mishka")
elif mi < ch:
    print("Chris")
    

