n=int(input())
a=[]
for i in range(n):
    x=input()
    a.append([len(x),x])
a=sorted(a)
for i in range(n-1):
    if not(a[i][-1]==a[i+1][-1] or a[i][-1] in a[i+1][-1]):
        print("NO")
        break
else:
    print("YES")
    for j in a:
        print(j[-1])