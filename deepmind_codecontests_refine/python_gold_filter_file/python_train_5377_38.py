n=int(input())
s=n//2
count=0
for i in range(1,s+1):
    if (n-i)%i==0:
        count+=1
    else:
        count+=0
print(count)
