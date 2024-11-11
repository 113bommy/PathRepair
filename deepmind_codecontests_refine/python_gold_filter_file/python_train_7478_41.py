a,b=map(ord,input().split())
print(['<' if a<b else '>','='][a==b])