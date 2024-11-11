a,b,c,d = map(int,input().split())
if a+b>c+b:
    print("Left")
elif a+b<c+b:
    print("Right")
else :
    print("Balanced")
