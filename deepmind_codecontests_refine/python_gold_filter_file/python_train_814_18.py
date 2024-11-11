a,b,c = map(str,input().split())
print("YES" if a[len(a)-1]==b[0] and b[len(b)-1]==c[0] else "NO")