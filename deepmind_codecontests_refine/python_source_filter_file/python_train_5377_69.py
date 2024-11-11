x=int(input())
count=0
for i in range(1,x+1):
    x=x-i
    if x%i==0:
        count+=1
print(count) 