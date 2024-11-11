a,b,c,d=map(int,input().split())
print("YES" if abs(a-c)<=d or (abs(a-b)<=d and abs(b-c)<=d) else "NO")