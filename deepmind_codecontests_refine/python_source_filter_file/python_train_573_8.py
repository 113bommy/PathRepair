a,b,c=map(int,input().split())


win=False
for i in range (c//b):
    if (c-(b*i))%a==0:
        win=True
if win==True:
    print("Yes")
else:
    print("No")
