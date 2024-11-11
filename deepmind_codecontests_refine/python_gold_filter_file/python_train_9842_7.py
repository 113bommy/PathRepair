d,h,v,e=map(int,input().split())
if v<=e*3.141592*(d/2)**2:print('NO')
else:print('YES');print(((d/2)**2*3.141592*h)/(v-e*3.141592*(d/2)**2))