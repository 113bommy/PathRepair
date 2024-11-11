n = input()

i=0

while len(n)!=0 and n[0]=='0':
    n=n[1:]

while len(n)!=0 and n[len(n)-1]=='0':
    n=n[:len(n)-2]


l = len(n)


s=True
for i in range(0, int(l/2)):
    if n[i]==n[len(n)-i-1]:
        continue
    
    else:
        s=False
        break


if s:
    print("YES")
else:
    print("NO")
