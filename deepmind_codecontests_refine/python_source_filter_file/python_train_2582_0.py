a,b,c = map(int,input().split())
print("No" if (a<c and c<b) or (b<c and c<a) else "Yes")