n = int(input())
l = input()
count = (n-11)//2
#print(count)
t = 0
for i in range(0, n-9):
    if l[i] == '8':
        t+=1
#print(t)
if t>count:
    print("YES")
else:
    print("NO")
