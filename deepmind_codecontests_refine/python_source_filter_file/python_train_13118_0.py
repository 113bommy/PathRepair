dic=[]
n=int(input())
cmd=[list(input().split()) for i in range(n)]
for c, l in cmd:
    if c=="insert":
        dic.append(l)
    if c=="find":
        if l in dic:
            print("yes")
        else:
            print("no")