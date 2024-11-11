n=int(input())
s=n//2
count=0
for i in range(1,s):
    if n%i==0:
        count+=1
    else:
        count+=0
print(count+1)
