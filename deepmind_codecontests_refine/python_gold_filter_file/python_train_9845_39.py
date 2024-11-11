n=int(input())
c=input()
a=0
d=0
for i in c:
    if i=='D':
        d+=1
    else:
        a+=1
if a>d:
    print("Anton")
elif a<d:
    print("Danik")
else:
    print("Friendship")