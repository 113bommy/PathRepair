def f(n,a,b):
    if n-b ==a :
        return b
    else:
        return n-a 
n,a,b=map(int,input().split())
print(f(n,a,b))