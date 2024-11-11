n,p1,p2,p3,t1,t2 = map(int, input().split())
lr = []

for _ in range(n):
    lr.append(list(map(int, input().split())))

result = 0
for i in range(n):
    result += p1*(lr[i][1]-lr[i][0])
    if i!=0:
        gap = lr[i][0]-lr[i-1][1]
        if gap>=t2+t1:
            result += p3*(gap-t2-t1)
            gap = t2+t1
        if gap>=t1:
            result += p2*(gap-t1)
            gap -= t2
        result += p1*gap

print(result)
