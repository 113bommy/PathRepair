o=[]
for _ in[0]*int(input()):n=int(input())-1;o+=[['2\n1 2'],[f'2\n{n-1} {n+1}\n{n} {n}']+[f'{n-2-i} {n-i}'for i in range(n-2)]][n>1]
print('\n'.join(o))