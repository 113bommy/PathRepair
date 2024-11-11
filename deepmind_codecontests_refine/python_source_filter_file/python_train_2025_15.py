import sys
n=int(input())
v=[int(i) for i in input().split()]
last=-1
first=v[0]
for i in range(len(v)):
    if v[i]<last:
        break
    else:
        last=v[i]
else:
    print(0)
    sys.exit()
pos=i
#print('pos=%d'%pos)
for i in range(i,len(v)):
    if v[i]>last or v[i]>first:
        print(-1)
        sys.exit()
    else:
        last=v[i]
print(len(v)-pos)
