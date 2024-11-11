n=int(input())
tmp=input().split()
num=0
for i in tmp:
    num+=int(i)
print('%.12f'%(num/n))