n=int(input())
s=0
for i in range(1,1+n):
    s+=i*(n//i)*(n//i+1)//2
print(s)