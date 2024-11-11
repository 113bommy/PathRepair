n=int(input())
a=[]
for i in range(n):
    a.append(input())

for i in range(n):
    if a[i][-3]=="_":
        print("FILIPINO")
    elif a[i][-1]=="u":
        print("JAPANESE")
    else:
        print("KOREAN")
