l=[input() for _ in range(int(input()))]
s=[]

isno=False
for i in l:
    if i=="A":
        s.append(1)
    else:
        try:
            _=s.pop()
        except:
            print("NO")
            isno=True
            break

if not isno and not s:print("YES")
elif not isno and s:print("NO")

