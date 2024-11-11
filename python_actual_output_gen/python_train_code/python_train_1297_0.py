# cook your dish here
n=int(input())
l=list(map(int,input().split()))
sum=0
for i in range(n//2):
    sum+=(l[i]+l[n-1-i])**2
print(sum)
    
    
   