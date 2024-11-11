import sys
s=0
p=[list(map(float,e.split(',')))for e in sys.stdin]
x,y=p[0]
for i in range(len(p)-2):
 a,b=p[i+1];c,d=p[i+2]
 s-=((a-x)*(d-y)-(b-y)*(c-x))/2
print(s)
