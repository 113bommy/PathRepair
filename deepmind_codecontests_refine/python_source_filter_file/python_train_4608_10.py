#https://codeforces.com/contest/1372/problem/B
for t in range(int(input())):
    a,b,n,m = map(int,input().split())
    a,b = min(a,b),max(a,b)
    if m>a and n+m>=b+b:
        print("Yes")
    else:
        print("No")                   
                  


