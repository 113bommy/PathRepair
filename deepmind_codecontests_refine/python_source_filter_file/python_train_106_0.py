import itertools
s=['S','H','C','D']
n=[str(i) for i in range(1,14)]
c=[x+' '+y for x,y in itertools.product(s,n)]
for _ in range(int(input())):
 c.remove(input())
print('\n'.join(c))