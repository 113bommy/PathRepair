n = int(input())
d= []
for i in range(n):
    lb,rb = list(map(int,input().split()))
    d.append((lb,1))
    d.append((rb,-1))
d.sort()
cnt = 0
for i in d:
    cnt+= i[1]
    if cnt >= 3:
        print("NO")
        exit(0)
print ("YES")
    
