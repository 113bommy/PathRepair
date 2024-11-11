t=int(input())
ans_list=[]
for i in range(t):
    a,b=map(int,input().split())
    if a==b*2:
        ans_list.append("YES")
    else:
        ans_list.append("NO")

for i in range(t):
    print(ans_list[i])