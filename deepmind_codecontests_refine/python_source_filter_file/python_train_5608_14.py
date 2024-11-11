a,b,c=map(int,input().split())
print(min(a%*b*c,a*b%*c,a*b*c%))