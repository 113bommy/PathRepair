n=int(input())
i=5
s=0
while n>0:
    s+=n//i
    n-=s*i
    i=i-1
print(s)

    
