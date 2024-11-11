n = int(input())
sq = input().split()
l = []
q = []
count = 0
temp = 0
flag = 0
for i in range(0, len(sq)):
    val = int(sq[i])
    l.append(val)
    if i == val:
        count += 1
    else:
        q.append(i)
if len(q) == 0:
    print(count - 2)
else:
    for j in q:
        if l[l[j]] == j:
            count += 2
            print(count)
            exit()
        else:
            temp = 1
    print(count + 1)
    
