a,b,c,d=map(int,input().split())
e,f=map(int,input().split())
if abs(a-c)%e==0 and abs(b-d)%f==0 and abs(a-c/e)%2==abs(b-d/f)%2:
    print("YES")
else:
    print("NO")
       