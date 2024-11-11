

k = int(input())
k = 2*k
list1 = []

for i in range(4):
    c = list(input())
    for j in range(len(c)):
        if c[j] != '.':
            c[j] = int(c[j])
            list1.append(c[j])
list1.sort()
print(list1)
t = 0
for i in range(len(list1)):
    a = list1[i]

    count = 2
    for j in range(len(list1)):
      if list1[i]!='.':
          if i!=j and list1[j] == list1[i] and t<list1[i] and count<=k:
            list1[j] = '.'
            count+=1
    if list1[i]!='.':
     if t < list1[i]:
        t = list1[i]
        list1[i] = '.'




temp = 1
for i in list1:
    if i!='.':
        print('NO')
        temp  = 0
        break

if temp == 1:
    print('YES')
