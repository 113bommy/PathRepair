a,b,c=map(int,input().split())
if a%c==0:
    d=int(b/c)-int(a/c)+1
else:
    d=int(b/c)-int(a/c)
print(d)