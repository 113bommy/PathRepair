a,b,c,d = map(int,input().split())
print(max(max(a*c,b*d),max(a*d,b*c)))