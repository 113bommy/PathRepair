c=0
for i in range(int(input())):
    s=input()
    a=s.split(" ")
    if(int(a[1])>=2400):
        if(int(a[2])>int(a[1])):
            c=1
            break
if(c==0):
    print("NO")
else:
    print("YES")
