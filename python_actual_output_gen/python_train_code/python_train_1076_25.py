a,b,c=map(int,input().split())
print("Yes" if (c-a-b)*(c-a-b) > 4*a*b and c!=0 else "No")