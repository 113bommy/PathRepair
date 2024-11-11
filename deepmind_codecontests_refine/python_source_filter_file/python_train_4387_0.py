x=input()
y=input()
a=y.split(" ")
n=0
for i in range(5):
    if a[i][0]==x[0] or a[i][1]==x[1]:
        print("YES")
        break
    else:
        n=n+1;

if n>0:
    print("NO")










