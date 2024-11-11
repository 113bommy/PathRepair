a,b,c,d=map(int,input().split())
print(max(a*c,max(a*d,max(c*b,d*b))))