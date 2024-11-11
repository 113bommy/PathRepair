g,c=map(int,input().split())
if  g==0:
    print('Impossible')
else:
    print(max(c,g), g+c-1 if c else g)

