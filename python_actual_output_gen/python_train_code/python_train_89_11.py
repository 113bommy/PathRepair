n=int(input())
if n%2==1:
    print(max(n, n*(n-1)*(n-2)))
else:
    if n%3==0:
        print(max(n, (n-1)*(n-2)*(n-3)))
    else:
        print(max(n, n*(n-1)*(n-2)))