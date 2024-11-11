a,b,c=map(int,input().split())
print("YES" if any((a*i)%b==c for i in range(a,b+1)) else "NO")