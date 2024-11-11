n=input()
c=0
for i in range(len(n)):
    if n[i]=="4" or n[i]=="7":
        c=c+1
        continue
if (c==4 or c==7):
    print("YES")
else:
    print("NO")
