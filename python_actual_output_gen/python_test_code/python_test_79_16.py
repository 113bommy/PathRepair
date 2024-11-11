
input()
a=input()[::2]

if ('23' or '32') in a: print('Infinite')
else:
       print('Finite\n',3*(a.count('12')+a.count('21'))+4*(a.count('13')+a.count('31'))-a.count('312'))
