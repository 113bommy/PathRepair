n=str(input())
s=0
for i in range(1,n+1):
    if i%3!=0 or i%3!=5:
        s+=i
print(s)