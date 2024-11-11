a,b,c = map(int,input().split())
print("YES" if 0 <= a+b-c <= a else "NO")