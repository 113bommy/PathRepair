n,m=map(int,input().split())
l=list(map(int,input().split()))
k=0
while 1 :
    if round((sum(l)+k*m)/(n+k))<m  :
        if ((sum(l)+k*m)/(n+k))%1==0.5 and  round(((sum(l)+k*m)/(n+k))-0.5)+1>=m:
            break
        k=k+1
    else :
        break
print(k)





    

