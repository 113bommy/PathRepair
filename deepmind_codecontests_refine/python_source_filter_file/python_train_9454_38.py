n = int(input())
for i in range(10**3):
    if n == i*(i+1)//2:
        x = i
        break
else:
    print("No")
    exit()
ans = [[] for i in range(x+1)]
app = 0
for i in range(1,x+1):
    for j in range(i):
        app += 1
        ans[j].append(app)
    ans[i].extend([k for k in range(i*(i-1)//2+1,i*(i+1)//2+1)])
print("Yes")
print(x)
for ansarr in ans:
    print(x, *ansarr, sep = " ")