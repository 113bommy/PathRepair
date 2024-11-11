x = int(input())

a = list(map(int,input().split()))

a.sort()
print(a)
if(len(a)%2==0):
    print(a[(len(a)-1)//2])
else:
    print(a[len(a)//2])

