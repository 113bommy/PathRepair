def sp(): return map(int, input().split())
def fun(x):
    return sum(int(i) for i in str(x))
t=int(input())
for _ in range(t):
    n,s=sp()
    x=n;
    if(fun(x)<=s):print(0);continue;
    else:# we need to check for (x+1) as next number need to be greater than it
        while fun(x+1)>s:x//=10
        x+=1;
        while (x<n):x*=10;
        print(x-n)