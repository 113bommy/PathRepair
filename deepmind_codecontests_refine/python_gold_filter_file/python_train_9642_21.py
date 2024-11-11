n = int(input())
a = input()
for i in range(n):
    if(a[0] == 'S' and a[-1] == 'F'):
        c=0
    else:
        c=1
if(c==0):
    print("YES")
elif(c==1):
    print("NO")
