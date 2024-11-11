n=int(input())
arr=list(map(int,input().split()))
a=set()
for i in arr:
    a.add(i)
#print(len(a))
if len(a)==1 or len(a)==2:
    print('YES')
elif len(a)==3:
    a=list(a)
    #a.sort()
    #print(a)
    if 2*a[1]==a[0]+a[2]:
        print('YES')
    else:
        print('NO')
else:
    print('NO')
