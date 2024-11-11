a,b = map(int,input().split())
if(abs(a-b)>=2 or (a==0 and b==0)):
    print("NO")
else:
    print("YES")
