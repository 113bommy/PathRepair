l=[4,7,47,74,444,447,474,744,747,777]
n=int(input())
ans=False
for i in l:
    if n%i==0:
        ans=True
        break
if ans:
    print("YES")
else:
    print("NO")
