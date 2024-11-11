reqd,min_to_bake,bake_per_min,oven = map(int, input().split())
h = "NO"
x = reqd // bake_per_min
print(x)
if reqd % bake_per_min == 0 and x * min_to_bake > min_to_bake + oven:
    h = "YES"
if reqd % bake_per_min != 0 and (x+1) * min_to_bake > min_to_bake + oven:
    h = "YES"
print(h)