n=int(input())

tree = [[0,1]]
for _ in range(n-1):
    tree = [ t+[i]  for t in tree for i in range(1,max(t)+2) ]
for t in tree:
    print( "".join([chr(ord("a")+tt-1) for tt in t[1:] ] ) )