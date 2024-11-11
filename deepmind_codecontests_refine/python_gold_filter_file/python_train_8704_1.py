n=int(input())
while n%10==0:
    n//=10
n=str(n)
a=True
for i in range(len(n)//2):
    if n[i]!=n[-i-1]:
        print("NO")
        a=False
        break
if a:
    print("YES")