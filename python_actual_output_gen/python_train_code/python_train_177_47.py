a,b,c,d,e=map(int,input().split())
f=a*b+d
g=a*c+e
if f<g:print('First')
elif f>g:print('Second')
else:print('Friendship')