def is_prime(x):
    if x==2:
        return 1
    elif x&1==0:
        return 0
    elif pow(2,x-1,x)==1:
        return 1
    else:
        return 0
N = int(input())
for i in range(N):
    n=int(input())
    c+=is_prime(n)
print(c)