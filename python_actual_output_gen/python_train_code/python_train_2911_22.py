n=int(input())
def fib(n):
    l1=[1,1]
    h=1
    while h<=n:
        h=l1[-1]+l1[-2]
        l1.append(h)
    return l1

l=fib(n)    
def f(n):
    for i in l:
        for j in l:
            for k in l:
                if i+j+k==n:
                    return [i,j,k]
print(f(n))