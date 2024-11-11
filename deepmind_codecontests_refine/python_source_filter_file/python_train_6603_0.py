s =[]
n = int(input())
z = ''
for _ in range(n):
    x = input()
    y =[]
    z +=x
    for i in x:
        y.append(i)
    s.append(y)

right = [s[i][i] for i in range(n)]
left = [s[i][n-i-1] for i in range(n)]

if left==right and len(set(left))==len(set(right)):
    l2 = s[0][1]
    if  z.count(l2)==pow(n,2)-((2*n)-1):
        print("YES")
    else:print("NO")
else:print("NO")