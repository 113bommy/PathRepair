#%%
tmp = input()
tmp = tmp.split()

n = int(tmp[0])
m = int(tmp[1])
k = int(tmp[2])

power = []
tmp = input()
tmp = tmp.split()
for i in range(n):
    power.append(int(tmp[i]))

school = []
tmp = input()
tmp = tmp.split()
for i in range(n):
    school.append(int(tmp[i]))

hack = []
tmp = input()
tmp = tmp.split()
for i in range(k):
    hack.append(int(tmp[i]))

#%%
count = 0
for i in range(k):
    num = hack[i]
    tmp_school = school[num-1]
    same = []
    strong = -1
    for j in range(n):
        if school[j] == tmp_school:
            same.append(j)
    #print(same)
    for obj in same:
        if power[obj] > strong:
            strong = power[obj]
            cham = obj
    if cham != num-1:
        count += 1
print(count)