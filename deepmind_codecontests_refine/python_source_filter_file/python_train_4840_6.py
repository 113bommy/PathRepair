n = int(input())
l = [0]*n
for i in range(n):
    l[i] = map(int,input().split(" "))
c = n
l2 = []
for i in l:
    flag = 0
    for j in i:
        if(j == 1 or j == 3):
            c = c = 1
            flag = 1
            break
    if(flag == 0):
        l2.append(l.index(i)+1)        
print(c)
print(*l2)