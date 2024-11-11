n, dest = input().split()
n = int(n)
dest = int(dest)
x = input().split()
for i in range(n-1):
    x[i] = int(x[i])
curr = 0
for i in range(n-1):
    if(curr == (dest-1)):
        print("YES")
        exit()
    if(curr > n-2):
        print("NO")
        exit()
    curr = curr+x[curr]

if(curr == dest):
    print("YES")
else:
    print("NO")
