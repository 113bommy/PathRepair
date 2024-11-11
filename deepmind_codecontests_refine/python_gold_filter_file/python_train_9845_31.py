n=int(input())
s=input()
c=0
d=0
for i in s:
    if i=="A":
        c+=1
    else:
        d+=1
if c>d:
    print("Anton")
elif d>c:
    print("Danik")
else:
    print("Friendship")