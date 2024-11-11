a,b,c,d,e,f = map(int, input().split())
water, suger = 0,0
dense = 0
waters = set()
sugers = set()
for i in range(0,31,a):
  for j in range(i,31,b):
    waters.add(j*100)
for i in range(0,f//2+1,c):
  for j in range(i,f//2+1,d):
    sugers.add(j)
waters = sorted(list(waters))
sugers = sorted(list(sugers))
for w in waters:
  for s in sugers:
    sw = w+s
    if sw > f or s > (w//100)*e or sw == 0:
      continue
    if s / (s+w) > dense:
      water,suger = sw,s
      dense = s/ (s+w)
print(water,suger)