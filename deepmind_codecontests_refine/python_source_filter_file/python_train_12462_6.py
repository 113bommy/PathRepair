c=p=0
for x in zip(input(),input()):
 x=x.count('0');p,c=((x,c),(x==p,c+1))[p+c>2]
print(c)