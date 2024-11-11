x=int(input())
count=0
for i in range(1,x):
    su=x-i
    if su%i==0:
        count+=1
print(count)
