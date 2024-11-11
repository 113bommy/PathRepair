p=[2,3,4,5,6,7,8,9,10,11,12,13,1]
a,b=map(int,input().split())
print('ABloibc e'[p.index(a)<p.index(b)::2] if a!=b else 'Draw') 