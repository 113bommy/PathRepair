n,k=map(int,input().split())
s=input()
l=list(input().split())
c,i,co=0,0,0
while(i<n):
    if(s[i] not in l):
        co=co+((c*(c+1))/2)
        c=0
    else:
        c+=1
    i+=1
if(c!=0):
    co=co+((c*(c+1))/2)
print(co)