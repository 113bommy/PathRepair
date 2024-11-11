#n,*a=map(int,open(0).read().split())
b=[a[i]for i in range(0,len(a),2)]
c=[a[i]for i in range(1,len(a),2)]
print(max(b)+c[b.index(max(b))])