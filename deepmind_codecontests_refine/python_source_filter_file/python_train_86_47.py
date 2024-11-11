a,b,c=map(int,input().split())
print("YES" if a+b+c == 2*max((a,b,c)) else "NO")