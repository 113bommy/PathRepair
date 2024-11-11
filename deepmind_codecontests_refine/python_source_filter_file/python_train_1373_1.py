# with open("file.in", "r") as fin:
#     white = fin.readline().split()
#     black1 = fin.readline().split()
#     black2 = fin.readline().split()

white = input().split()
black1 = input().split()
black2 = input().split()

x1,y1,x2,y2 = map(int, white)
x3,y3,x4,y4 = map(int, black1)
x5,y5,x6,y6 = map(int, black2)

# 3 CASES: Blacks intersect vertically, horizontally, completely cover

# Intersecting Vertically
blockX = False
largest = max(x4, x6)
smallest = min(x3, x5)
mid1 = min(x4, x6)
mid2 = max(x3, x5)
largeY = min(y4, y6)
smallY = max(y3, y5)

if largest >= x2 and smallest <= x1 and mid1-mid2 >= 0 and largeY >= y2 and smallY <= y1:
    blockX = True

# Intersecting Horizontally
blockY = False
largest = max(y4, y6)
smallest = min(y3, y5)
mid1 = min(y4, y6)
mid2 = max(y3, y5)
largeY = min(x4, x6)
smallY = max(x3, x5)

if largest >= y2 and smallest <= y1 and mid1-mid2 >= 0 and largeY >= x2 and smallY <= x1:
    blockY = True

# COVERED X
complete = False
if x6 >= x2 and x5 <= x1 and y6 >= y2 and y5 <= y1:
    complete = True
elif x4 >= x2 and x3 <= x1 and y4 >= y2 and y3 <= y1:
    complete = True

covered = False
if blockX or blockY or complete:
    covered = True


ans = "YES"
if covered:
    ans = "NO"

print(ans)
print(blockX, blockY, complete)