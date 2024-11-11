q=lambda:map(int,input().split())
qi=lambda:int(input())
qs=lambda:input().split()
x,y,z=q()
a,b,c=q()
if x>a or y>(b+(a-x)) or z>(c+(y-(b+(a-x)))):
    print("NO")
else:print("YES")