sx,sy,tx,ty = map(int,input().split(' '))
w,h = abs(sx-tx),abs(sy-ty)

res = 'U'*h+'R'*w+'D'*h+'L'*w
res += 'L'+'U'*(h+1)+'R'*(h+1)+'DR'+'D'*(h+1)+'L'*(w+1)+'U'
print(res)