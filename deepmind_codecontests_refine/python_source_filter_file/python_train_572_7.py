a,b,c=map(int,input().split())
i=0
z=95
while (c-(b*i))>0 :
    z=(c-(b*i))%a
    i+=1
    if z==0:break
print(["No","Yes"][z==0]) 