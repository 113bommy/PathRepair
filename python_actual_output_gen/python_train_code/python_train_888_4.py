n=int(input())
sum=n
while True:
    if n==1:
        break
    q=int(n**0.5)
    for i in range(2,q):
        if n%i==0 and i!=1:
            n=n//i
            sum+=n
            break
    else:
        sum+=1
        n=1
        break
print(sum)