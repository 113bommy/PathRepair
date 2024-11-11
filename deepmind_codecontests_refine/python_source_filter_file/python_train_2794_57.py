x,a,b = map(int,input().split())
print('AB'[abs(a-x)<abs(b-x)::2])