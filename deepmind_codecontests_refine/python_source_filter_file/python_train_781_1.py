ins = input().split(" ")
num, wid, que = int(ins[0]), int(ins[1]), int(ins[2])

t = [-1]
ins = input().split(" ")
for i in range(0, num):
    t.append(int(ins[i]))

dis = []

for i in range(0, que):
    ins = input().split(" ")
    qt, fid = int(ins[0]), int(ins[1])

    if qt == 1:
        imi = t[fid]
        for j in range(0, len(dis)):
            if dis[j][1] < imi:
                dis.insert(j, [fid, t[fid]])
                break
        else:
            if len(dis) < wid:
                dis.append([fid, t[fid]])
        if len(dis) > wid:
            dis.pop(wid)

    else:
        for j in range(0, len(dis)):
            if dis[j][0] == fid:
                print("Yes")
                break
        else:
            print("No")


