a,b,c,d = map(int,input().split())
X = max(a,c)
B = min(b,d)
print(max(0,B-X))