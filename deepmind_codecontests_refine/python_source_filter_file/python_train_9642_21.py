n = int(input())
a = input()
for i in range(n):
    if(a[0] == 's' and a[-1] == 'f'):
        c=0
    else:
        c=1
if(c==0):
    print("yes")
elif(c==1):
    print("no")
