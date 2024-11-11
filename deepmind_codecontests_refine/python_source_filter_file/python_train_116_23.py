n = int(input())
s = input()
l = list()
for i in s:
    l.append(ord(i))
a = 0
for i in range(0,n-1):
    if l[i] > l[i+1]:
        a = 1
        break
if(a==0):
    print("NO")
else:
    print("YES")
    print(i-1,i)
