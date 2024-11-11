R=lambda:map(int,input().split())
n,m,k=R()
a=sorted(zip(R(),range(n)))[-m*k:]
print(sum(x for x,_ in a),*sorted(i+1for _,i in a)[m::m])