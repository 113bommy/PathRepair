a, b = map(int, input().split())
s = input()
f = 0
t = s.split('.')
for i in t:
    if(len(i)>b or len(i)==b):
        f=1
        break
    else:
        f=0
if(f==1):
    print("NO")
else:
    print("YES")
