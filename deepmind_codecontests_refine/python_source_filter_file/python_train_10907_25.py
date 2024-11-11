x,k,d=map(int,input().split())
s=x%d
t=x//d
if k<t:
    print(x-k*d)
else:
    print(abs(s-(k-t)%2*d))