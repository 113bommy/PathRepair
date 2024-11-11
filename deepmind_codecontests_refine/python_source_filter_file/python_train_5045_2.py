every=[]
for i in range(int(input())):
    line=list(map(int,input().split()))
    every.append(line)
every.sort(key=lambda x:x[0])
every.sort(key=lambda x:x[1])
day=every[0][1]
for i in every:
    if i[1]>=day:
        day=i[1]
    else:
        day=i[0]
print(day)
