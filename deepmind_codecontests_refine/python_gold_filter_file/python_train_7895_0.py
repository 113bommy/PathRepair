sx, sy, tx, ty = map(int, input().split())

X = tx-sx
Y = ty-sy

print('R'*X+'U'*Y+'L'*X+'D'*Y+'D'+'R'*(X+1) +
      'U'*(Y+1)+'L'+'U'+'L'*(X+1)+'D'*(Y+1)+'R')
