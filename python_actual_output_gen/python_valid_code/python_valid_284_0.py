n,m=map(int , input().split())

s=[]

while n:
    s.append(n%m)
    n//=m

ss=set(s)
print(s,ss)
if(len(s)==len(ss)):
    print("YES")
else : print("NO")