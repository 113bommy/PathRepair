a,b,c,d=map(int,input().split())
print(max(max(a*d,a*c),max(b*c,b*d)))