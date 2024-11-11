a,b,c,d=map(int,input().split())
ans="Yes" if abs(c-a)<=d or (abs(b-a) and abs(c-b))<=d else "No"
print(ans)