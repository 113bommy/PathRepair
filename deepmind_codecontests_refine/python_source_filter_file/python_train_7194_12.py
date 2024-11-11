n = int(input())
l = list(map(int,input().split()))
l.append(1001)
l = [0] + l

smax = 0
s = 1

for i in range(1,len(l)):
    if l[i] - l[i-1] == 1:
        s = s + 1
        smax = max(s,smax)
    else:
        smax = max(s,smax)
        s = 1
        
print(smax - 2)
