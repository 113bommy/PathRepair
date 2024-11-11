n=int(input())
k=input()
a=d=0
for i in k:
    if i=='A':
        a+=1
    else:
        d+=1
if a>d:
    print("Anton")
elif a<d:
    print("Danik")
else:
    print("Friendship")

