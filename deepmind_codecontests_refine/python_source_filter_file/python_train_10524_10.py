n = int(input())
max=0
a = sum(map(int, input().split())) 
for j in range (1,n):
    b=sum(map(int, input().split())) 
    if(a<b):
        max+=1
        #print(max)
print(max)