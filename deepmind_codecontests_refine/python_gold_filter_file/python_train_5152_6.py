a=input()
b=[]
for i in range(int(input())):
    b.append(input())
b=sorted(b)
for j in range(len(b)):
    if b[j][0:len(a)]==a:
        print(b[j])
        break
else:
    print(a)