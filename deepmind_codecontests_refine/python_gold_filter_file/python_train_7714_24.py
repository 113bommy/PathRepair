l,r = map(int,input().strip().split())

print("YES")
for i in range(l + 1,r + 1,2):
    print("%d %d"%(i,i - 1))