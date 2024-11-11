a,b,c,d=map(int,input().split())

print("Yes" if ((abs(a-b)<=d and (abs(c-b)<=d)) or (abs(c-a)<=d) else "No") 
