n=int(input())
flag=0
for _ in range(n):
    inp=list(input().split())
    if(int(inp[2])>int(inp[1]) and int(inp[1])>2400):
        flag=1
        break
print("YES" if flag==1 else "NO")
