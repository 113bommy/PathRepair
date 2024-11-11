a,b,c,d=map(int, input().split())
print(a*b*int(a*b>=c*d)+c*d*int(a*b<c*d))