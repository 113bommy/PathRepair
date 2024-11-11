n=int(input());a=list(map(int,input().split()));f,b,c=0,sum(a),float('inf')
for i in range(n):
  f,b=f+a[i],b-a[i]
  c=min(c,abs(f-b))
print(c)