n=input()
n2=list(map(int, n))
if sum(n2)==1 and sum(n2[1:])==0:print('10')
else: print(sum(n2))