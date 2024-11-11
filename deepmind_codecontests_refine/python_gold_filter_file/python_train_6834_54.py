k=int(input())
if(k>36):
    print(-1)
else:
    a=k//2;
    b=k%2;
    s='8'*a+'9'*b
    print(s)