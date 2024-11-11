def is_prime(x):
    if(x%2==0 and x!=2)or x==1:
        return 0
    y=3
    while y*y<=x:
        if x%y==0:
            return 0
        y+=2
    return 1

n = int(input())
for i in range(1,1001):
    if not is_prime(n*i+1):
        print(i)
        break