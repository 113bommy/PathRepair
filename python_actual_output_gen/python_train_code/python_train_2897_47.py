a,b,c=map(int,input().split())
print(max(3*a+3if a<b<c else 0,3*b if b-2<a and b<c else 0,3*c-3 if c-3<a and c-2<b else 0))