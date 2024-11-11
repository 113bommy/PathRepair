n=int(input())
l=[]
if n==1 or n==2:
    print(0)
    exit()
for i in range(1,int(n**0.5)+1):
    if n%i==0 and i!=n//i:
        l.append(n//i)

print(sum(l)-len(l))