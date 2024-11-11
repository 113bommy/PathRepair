n = int(input())
counter = 0
p = 1
for i in range(2,round(n**0.5)+1):
    if n%i==0:
        p=0 
        while n%i==0:
            n//=i
        if n==1:
            print(p)
        else:
            print(1)
        break
if p == 1:
    print(n)