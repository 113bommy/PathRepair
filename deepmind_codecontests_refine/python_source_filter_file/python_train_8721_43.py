n,m = map(int, input().split())

ls = list(map(int, input().split()))
ls = sorted(ls,reverse=True)

print("Yes" if ls[m-1]*4*m >sum(ls) else "No")

