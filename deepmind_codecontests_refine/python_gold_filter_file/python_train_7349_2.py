s=input()
u=' '.join(s.split())
u=u.replace(', ',',')
u=u.replace(' ,',',')
u=u.replace(',',', ')
u=u.replace('... ','...')
u=u.replace(' ...','...')
u=u.replace('...',' ...')
if u[0]==' ':
    u=u[:0]+u[1:]
if u[-1]==' ':
    u=u[:-1]
print(u)