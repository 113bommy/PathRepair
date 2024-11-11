n = int(input())
l_list = []
r_list = []
c=0
l0c = 0
l1c = 0
r0c = 0
r1c = 0
for i in range(0,n):
    l,r = map(int,input().split())
    l_list.append(l)
    r_list.append(r)
for j in range(0,n):
    if l_list[j] == 1:
        l1c+=1
    elif l_list[j] == 0:
        l0c+=1
    if r_list[j] == 1:
        r1c+=1
    elif r_list[j] == 0:
        r0c+=1
if l1c < l0c:
    c+=l1c
elif l0c < l1c:
    c += l0c
if r1c < r0c:
    c+=r1c
elif r0c < r1c:
    c += r0c
print(c)

    


