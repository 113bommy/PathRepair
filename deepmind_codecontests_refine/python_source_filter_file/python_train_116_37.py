n = int(input())
s = input()
a = []
b = []
x = 'a'
has_ans = 0
for i in range(0,26):
    a.append(s.rfind(x))
    b.append(s.find(x))
    x = chr(ord(x)+1)
for x in range(0, 26):
    if a[x] == -1:
        continue
    for y in range(25, x, -1):
        if b[y] == -1:
            continue
        if a[x] > b[y]:
            print("YES")
            print(b[y],a[x])
            has_ans = 1
            break
    if has_ans == 1:
        break
if has_ans == 0:
    print("NO")

        
