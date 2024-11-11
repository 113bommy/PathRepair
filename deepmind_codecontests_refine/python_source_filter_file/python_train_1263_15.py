def inint():
    return int(input())
def mp():
    return map(int,input().split())
b,k=mp()
a=list(mp())
if b%2==0:
    if a[-1]%2==0:print('even');exit()
    else:print('odd');exit()
else:
    cho=0
    for i in range(1,k):
        if a[i]%2!=0:cho+=1
    if a[-1]%2!=0:cho+=1
    if cho%2==0:print('even')
    else:print('odd')