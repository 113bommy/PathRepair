
a , b = map(int , input().split())
cnt = 0
l = []
for i in range(a):
    x = [int(x) for x in input().split()]
    x.sort()
    if x[1] < b:
        cnt += 1
        l.append(x[0])
        
print(cnt)
l.sort()
for j in l:
    print(j , end = ' ')