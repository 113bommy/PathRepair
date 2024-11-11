d={}
for i,c in enumerate(input()):
    if c in d and i-d[c]<2:
        print(d[c],i)
        break
    d[c]=i
else:
    print(-1,-1)