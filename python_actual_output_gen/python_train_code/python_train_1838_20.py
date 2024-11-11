from sys import stdin
input=lambda:stdin.readline().strip()
n=int(input())
max7=0
nn=-1
n7=0
while n>=7:
    n=n-7
    n7+=1
    if n%4==0:
        nn=n
        max7=n7
if nn%4==0:
    print('4'*(nn//4),'7'*max7,sep='')
else:
    print(-1)
