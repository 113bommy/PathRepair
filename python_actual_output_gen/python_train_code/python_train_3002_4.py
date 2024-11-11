#ZadA
n=int(input())
line=[]
for i in range(n):
    line.append(input())
ans={'purpule':'Power','green':'Time','blue':'Space','orange':'Soul','red':'Reality','yellow':'Mind'}
n=len(ans)-len(line)
print(n)
for colors in ans.keys():
    if colors not in line:
        print(ans[colors])