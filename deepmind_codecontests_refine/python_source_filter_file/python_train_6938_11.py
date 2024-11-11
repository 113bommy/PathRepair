from math import*
def get(x):
    if x==0:
        print(1)
        return
    i=1
    while i*i<=x:
        if not(x%i):
            a,b=int(x/i),i
            if(not((a+b)%2)):
                n=int((a+b)/2)
                n_m=int((a-b)/2)
                if n_m:
                    m=int(n/n_m)
                    if(int(n/m)==n_m and m<=n):
                        print(n,m)
                        return
        i+=1
    print(-1)
    return

n=int(input())
for i in range(n):get(int(input()))