size, want = map(int,input().split())

unique = set()

l = list(map(int,input().split()))
ans = []
for i in l:
    unique.add(i)

step=0
if len(unique) >= want:
    print("YES")
    for j,i in enumerate(l):
        if step>want:
            break
        if i in unique:
            unique.remove(i)
            ans.append(str(j+1))
            step+=1
    print(" ".join(ans))
else:
    print("NO")
