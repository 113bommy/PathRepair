s = input()
vert = 0
gor = 0
ans = []
for i in s:
    if i == '0' and vert == 0:
        ans.append(1)
        ans.append(1)
        vert = 1
    elif i == '0' and vert == 1:
        ans.append(1)
        ans.append(3)
        vert = 0
    elif i == '1' and gor == 0:
        ans.append(2)
        ans.append(1)
        gor = 1
    elif i == '1' and gor == 1:
        ans.append(2)
        ans.append(2)
        gor = 2
    elif i == '1' and gor == 2:
        ans.append(2)
        ans.append(3)
        gor = 3
    elif i == '1' and gor == 3:
        ans.append(2)
        ans.append(4)
        gor = 0
for i in range(len(ans)):
    if i % 2:
        print(ans[i])
    else:
        print(ans[i], end=" ")