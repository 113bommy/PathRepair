H, W = [int(hoge) for hoge in input().split()]
print("Possible") if sum([input().count("#") for h in range(H)]) == H+W-1 else print("Impossible")
