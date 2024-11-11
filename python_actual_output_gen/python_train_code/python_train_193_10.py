n,L,a = [int(i) for i in input().split()]
l = [(0,0)]
for i in range(n):
    t1,t2 = [int(i) for i in input().split()]
    l.append((t1,t1+t2))
l.append((L,L))
count = 0
for i in range(n+1):
    inter = l[i+1][0] - l[i][1] 
    if(inter > a):
        count += inter//a 
print(count)