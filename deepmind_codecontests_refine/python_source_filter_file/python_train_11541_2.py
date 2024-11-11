a,b,c=map(int,input().split())
x = any((a*i)%b==c for i in range(1,b+1))
print("Yes" if x else "No")