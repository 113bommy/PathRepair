n=int(input())
for i in range(n,2,-1):
    if n%i==0:
        print(i,end='')
        n=i