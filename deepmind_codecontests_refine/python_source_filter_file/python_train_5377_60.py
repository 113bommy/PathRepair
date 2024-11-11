n=int(input())
count=0
for i in range(2,9):
    if(n%i==0):
        count=count+1
print(count+1)