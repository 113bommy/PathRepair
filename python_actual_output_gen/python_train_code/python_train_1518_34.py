s=input()
l=input().split()
a=s[0]
b=s[1]
c=0
for i in range(len(l)):
    if(a in l[i] or b in l[i]):
        print("YES")
        c=1
        break
    if(c==0):
        print("NO")