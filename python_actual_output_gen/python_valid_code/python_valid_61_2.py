res=0
res1=0
lis1=input().split()
lis2=input().split()
p=int(input())
for i in lis1:
    res+=int(i)
for i in lis2:
    res1+=int(i)
if res % 5 != 0:
    res=res / 5 + 1
else:
    res=res//5
if res1 % 10 != 0:
    res1=res1 / 10 + 1
else:
    res1=res1//10
if res1+res <= p:
    print("YES")
else:
    print("NO")