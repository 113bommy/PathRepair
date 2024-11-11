n=int(input())
#a=list(map(int,input().split()))
m=str(input())
sum=0
for i in range(n):
    if m[i]=='2' and m[i]=='4' and m[i]=='6' and m[i]=='8':
        sum+=i+1
print (sum)