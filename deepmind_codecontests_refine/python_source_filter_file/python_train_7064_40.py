s=str(input())

p=list('ABDEGHIJKLMNOPQRSTUVWXYZ')

for i in p:
    s.replace(i,'')

if 'CF' in s:
    print('Yes')
else:
    print('No')
    