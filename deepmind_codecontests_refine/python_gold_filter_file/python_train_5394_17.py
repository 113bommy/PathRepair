_ = input()
l = [int(i)for i in input().split()]
print("Yes" if 2*max(l) < sum(l) else "No")
