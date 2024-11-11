def d(i,n):
    if(i==2 and n%2==0):
        return 2;
    while(i**2<n):
        if(n%i == 0):
            return i
        i+=1
    return n;
t=int(input())
for _ in range(t):
    n=int(input())
    a = d(2,n);
    b= d(a+1,n/a);
    c = n/(a*b)
    if(c>=2 and c!=a and c!=b):
        print("YES")
        print(a,b,c)
    else:
        print("NO")