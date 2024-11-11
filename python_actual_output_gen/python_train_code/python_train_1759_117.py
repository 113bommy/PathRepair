a,b,c,d=map(str, input().split())
print(a*b*int(a*b>=c*d)+c*d*int(a*b<c*d))