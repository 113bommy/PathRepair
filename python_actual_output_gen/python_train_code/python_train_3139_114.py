a,b,c,d=map(int,input().split())
print(max([0,max([a,c])-min([b,d])]))