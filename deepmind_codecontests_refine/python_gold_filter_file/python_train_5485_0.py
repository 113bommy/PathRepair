n = int(input())
l= []
for i in range(n):
    l.append(input())
l= sorted(l,key=lambda w: len(w))
for i in range(len(l)-1):
    if l[i] not in l[i+1]:
        print('NO')
        exit()
print('YES')
for i in l:
    print(i)