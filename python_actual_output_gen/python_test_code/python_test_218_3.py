a,b,c=map(int,input().split())
x = any((a*i)%b==c for i in range(1,b+1))
print(x)
print("YES" if x else "NO")