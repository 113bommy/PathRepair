h, w = map(int, input().split())
list=["."+input()+"." for i in range(h)]
list=["."*(w+2)]+list+["."*(w+2)]
a=0
for h in range(h):
    for w in range(w):
        if list[h][w] == "#":
            if list[h+1][w] == "." and list[h-1][w] == "." and list[h][w-1] == "." and list[h][w+1] == ".":
                a=1
print("Yes" if a==0 else "No")