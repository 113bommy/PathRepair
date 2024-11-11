
n,i=map(int,input().split(' '))
sound=list(map(int,input().split(' ')))
sound.sort()
limit=2**((i*8)//n)
l=[0]
for i in range(1,n):
    if(sound[i-1]!=sound[i]):
        l.append(i)
if(len(l)<=limit):
    print('0a')
else:
    print(n-max(l[i+limit]-l[i] for i in range(len(l)-limit)))
#111