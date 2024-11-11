n=input()
if len(n)<=6:print("NO");exit()
for x in range(len(n)-4):
    if n[x]=="0":
        if len(list(filter(lambda y:y=="0",n[x:x+7]))) == 7:
            print("YES")
            exit()
    elif n[x]=="1":
        if len(list(filter(lambda y:y=="1",n[x:x+7]))) == 7:
            print("YES")
            exit()
print("NO")
