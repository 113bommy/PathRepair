a,b,c,d = map(int,input().split())
x=c-a
y=d-b
print('R'*x+'U'*(y+1)+'L'*(x+1)+'D'*(y+1)+'R'+'U'*x+'R'*(x+1)+'D'*(y+1)+'L'*(x+1)+'U')
