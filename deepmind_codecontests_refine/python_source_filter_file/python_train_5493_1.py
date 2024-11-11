l = []
t = 2
n = int(input())
for x in range(n):
    p = input()
    l.append(p)

for i in range(n):
    for j in range(n-i-1):
        if(len(l[j]) > len(l[j+1])):
            l[j],l[j+1] = l[j+1],l[j]

l = l[::-1]
i = 0
j = 1
while(j < len(l)):
    one = l[0]
    two = l[1]

    if two in one:
        t = 0

    else:
        t = 1

    if(t == 1):
        print("NO")
        break

    i = i+1
    j = j+1

if(t == 0):
    print("YES")
    l = l[::-1]
    for u in l:
        print(u)
