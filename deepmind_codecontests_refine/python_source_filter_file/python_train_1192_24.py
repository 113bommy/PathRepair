a ="""qwertyuiop
      asdfghjkl;
      zxcvbnm,./"""

y = list(a)
print(y)
m = input()
c= list(input())

d=[]
if m =="R":
    for j in c:
        for i in range(1,len(a)):
            if j == a[i]:
                d.append(a[i-1])
elif m=="L":
    for j in c:
        for i in range(0, len(a)):
            if j == a[i]:
                d.append(a[i + 1])

for i in d:
    print(i, end="")