a,b,c=map(int,input().split())
print(int((a*b/c)**0.5)*4 + ((c*b/a)**0.5)*4 +((a*c/b)**0.5)*4 )