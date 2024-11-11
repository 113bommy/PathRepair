a,b=map(int,input().split())
s=a
while a>=b:
    di=a/b 
    s+=di 
    r=a%b 
    a=di+r
print(int(s))