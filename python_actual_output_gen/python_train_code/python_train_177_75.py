matn,yak,duyum,se1,se2=map(int,input().split())
s=yak*matn+se1*2
s2=duyum*matn+se2*2
if s>s2:print('First');exit()
if s<s2:print('Second');exit()
print('Friendship')