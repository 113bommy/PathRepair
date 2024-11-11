M=int(input())
dig=0
sum=0

for i in range(M):
    d,c=map(int,input().split())
    dig+=c
    sum+=d*c
    
print(dig-1+sum//10)