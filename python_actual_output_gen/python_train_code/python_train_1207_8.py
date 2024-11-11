n,k=map(int,input().split())
s=input()
for i in range(k):
    x,y,c,d=input().split()
    a=int(x)
    b=int(y)
    if b<n:
        s=s[:a-1]+s[a:b].replace(c,d)+s[b-1:]
    else:
        s=s[:a-1]+s[a:b].replace(c,d)
print(s)