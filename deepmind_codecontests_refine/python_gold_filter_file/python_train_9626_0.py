import bisect

n = int(input()) 
a = [int(x) for x in input().split()]
a.sort()
m = int(input()) 
b = [int(x) for x in input().split()]
b.sort() 
maxRes = n*3-m*3
pos = [n*3, m*3]
for i in range(n):
    k = bisect.bisect_left(b, a[i])
    res = (i*2+(n-i)*3)-(k*2+(m-k)*3)
    #print(res)
    if (res > maxRes) or ((res == maxRes) and (i*2+(n-i)*3 > pos[0])):
        maxRes = res
        pos = [i*2+(n-i)*3, k*2+(m-k)*3] 
    #print(i, k, pos) 
if (n*2-m*2 > maxRes) or ((n*2-m*2 == maxRes) and (n*2 > pos[0])) :
    pos = [n*2, m*2]
print(':'.join(list(map(str, pos))))