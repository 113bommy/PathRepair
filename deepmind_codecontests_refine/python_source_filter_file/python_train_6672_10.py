n = int(input())

l = []
for i in range(n):
    w = list(map(int,input().split()))
    w.sort(reverse = True)
    l.append(w)

print(l)
mx = l[0][0]
flag = 0

for i in range(1 , n):
    if l[i][0] > mx :
        if l[i][1] > mx :
            flag = 1
            break
        else:
            mx = l[i][1]

    else:
        mx = l[i][0]

if flag == 1 :
    print('NO')

else:
    print('YES')