b=1
for e in iter(input,'0 0'):
 if b:print();b=0
 s,t=map(int,e.split())
 u=[y for y in range(s,t+1)if y%4==0 and y%100!=0 or y%400==0]
 if u:
  for y in u:print(y)
 else:print('NA')
