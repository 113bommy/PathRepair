a,b=map(int,input().split())
if b==0 and a==0:
    print("NO")
elif a==b or abs(a-b)==1:
    print("YES")
else:
    print("NO")