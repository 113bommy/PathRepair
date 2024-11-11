l = input().split()
n, m = map(int, l)
x = input().split()
y = input().split()
ans = ""
k = False
for i in x:
    if i in y:
        ans+=i+" "
        k = True
if k==True:
    print(ans.strip())
else:
    print(0)
