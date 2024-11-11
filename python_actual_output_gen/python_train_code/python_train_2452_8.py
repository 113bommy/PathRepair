n = int(input())
l = list(map(int,input().split()))
s = 0
c = 0
c1 = 0
for i in range(n):
    if(l[i] < 0):
        s = s + abs(-1 - l[i]) 
        c += 1
    else:
        s = s + abs(1 - l[i])
    if(l[i] == 0):
        c1 += 1
if(c % 2 != 0):
    if(c1 == 1):
        print(s)
    else:
        print(s + 2)
else:
    print(s)
