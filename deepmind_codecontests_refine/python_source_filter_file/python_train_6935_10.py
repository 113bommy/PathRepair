h, m, s, t1, t2 = list(map(int, input().split()))

h = (h % 12) * 60 * 5 + m
t1 = (t1 % 12) * 60 * 5
t2 = (t2 % 12) * 60 * 5
m = m * 60 + s
s = s * 60

list = [(h, "h"), (m, "m"), (s, "s"), (t1,"t1"), (t2,"t2")]
l = list[:]


for j in range(4):
    if list[j][1] != "t1" and list[j][1] != "t2" and list[j][0] == t1 or list[j][0] == t2:
        l.remove(list[j])

l.sort()

list = l[:]


for i in range(len(list)):
    if list[i][1] == "t1":
        if i != len(list) - 1 and i != 0:
            if list[i + 1][1] == "t2" or list[i - 1][1] == "t2":
                print("YES")

            else:
                print("NO")

        elif i == len(list) - 1:
            if list[0][1] == "t2" or list[-2][1] == "t2":
                print("YES")

            else:
                print("NO")

        elif i == 0:
            if list[i + 1][1] == "t2" or list[-1][1] == "t2":
                print("YES")

            else:
                print("NO")