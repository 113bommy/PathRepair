a,b,c,d=map(int,input().split())
print("Yes" if abs(a-b)<=d or abs(c-a)<=d and abs(b-c)<=d else "No" )

