input()
x=0
a=[0]
for i in input():a+=a[-1]+1-2*(i=='D')
print(a)