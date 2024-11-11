SX,SY,TX,TY=map(int,input().split())
vx=TX-SX
vy=TY-SY
print('U'*vy+'R'*vx+'L'*vx+'D'*vy+'L'+'U'*(vy+1)+'R'*(vx+1)+'D'+ 'R'+'D'*(vy+1)+'L'*(vx+1)+'U')