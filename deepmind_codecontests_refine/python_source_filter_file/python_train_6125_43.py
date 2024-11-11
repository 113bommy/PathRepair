A,B,C,D=map(int,input().split())
if A+B==C+D: print('Balanced')
else: print('Left' if A+B > C+D else 'Righe')