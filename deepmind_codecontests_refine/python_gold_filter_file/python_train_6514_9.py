a,b = map(int,input().split())
if(abs(b-a)>=2 or (a==0 and b==0)):
    print("NO")
else:
    print("YES")