sx, sy, tx, ty = map(int, input().split())

x = tx - sx
y = ty - sy

print('U'*y+'R'*x+'U'+'L'*(x+1)+'D'*y+'R'*(x+1)+'U'*y+'R'+'D'*(y+1)+'L'*(x+1)+'U')