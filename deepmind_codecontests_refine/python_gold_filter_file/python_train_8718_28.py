c = {'purple':'Power', 'green':'Time', 'blue':'Space', 'orange':'Soul', 'red':'Reality', 'yellow':'Mind'}
n = int(input())
d = []
e = []
for i in range(n):
    d.append(input())
for i in c:
    if i not in d:
        e.append(c[i])
print(len(e))
for i in e:
    print(i)
