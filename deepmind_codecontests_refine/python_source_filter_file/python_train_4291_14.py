n = int(input())
l = input()
s = [l[i:i+1] for i in range(len(l))]
path = []
temp = 'B'
for i in range(len(s)):
    if i<n-1:
        if s[i]!=temp:
            path.append(i)
            if s[i+1]!=temp:
                s[i+1] = temp
            else:
                s[i+1] = 'W'
            s[i] = temp
flag = 0
for i in range(len(s)):
    if i<n-1:
        if s[i]!=s[i+1]:
            flag = 1
            break
if(flag==0):
    print(len(path))
    for i in path:
        print(i,end=" ")
else:
    temp = 'W'
    for i in range(len(s)):
        if i<n-1:
            if s[i]!=temp:
                path.append(i)
                if s[i+1]!=temp:
                    s[i+1] = temp
                else:
                    s[i+1] = 'B'
                s[i] = temp
    flag = 0
    for i in range(len(s)):
        if i<n-1:
            if s[i]!=s[i+1]:
                flag = 1
                break
    if(flag==0):
        print(len(path))
        for i in path:
            print(i,end=" ")
    else:
        print(-1)