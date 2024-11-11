a = []
for _ in range(4):
    a.append(input())
flag = 0
for i in range(3):
    for j in range(3):
        s = [a[i][j],a[i+1][j],a[i][j+1],a[i+1][j+1]]
        if s.count(".")>=3 or s.count("#")>=3:
            flag = 1
            break
if flag == 1:
    print("YES")
else:
    print("NO")


    
