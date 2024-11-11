a,b=map(int,input().split())
sum=0
sum+=a*int(b/5)
sum+=int(a/5)*b%5
if a%5+b%5>=5:
    sum+=(a%5+b%5)%5+1
print(sum)