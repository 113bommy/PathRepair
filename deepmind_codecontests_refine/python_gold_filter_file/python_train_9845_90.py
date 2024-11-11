n=int(input())
s=input()
a=d=0
for c in s:
    if c=="A":
        a+=1
    else:
        d+=1
if a>d:
    print("Anton")
elif a<d:
    print("Danik")
else:
    print("Friendship")