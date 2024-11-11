t,_,s=open(0).read().partition('\n')
h,w=map(int,t.split())
a,b=h//2*(w//2),h%2and w%2
d=[b,(h*w-a*4-b)//2,0,a]
for i in map(s.count,set(s)-{'\n'}):
  for j in(3,1,0):
    while d[j]and i>j:
      i-=j+1
      d[j]-=1
print('YNeos'[sum(d.values())>0::2])