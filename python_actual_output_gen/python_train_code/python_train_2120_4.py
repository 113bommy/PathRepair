# ##############################

n = int(input())
x,y = map(int, input().split())

way1 = 0
way2 = 0

d1 = (y - 1) + abs(x - y)
d2 = (x - 1) + abs(y - x)
way1 += min(d1, d2)


d1 = (n - y) + abs(x - n)
d2 = (n - x) + abs(y - n)
way2 += min(d1, d2)
#print(d1, d2)

# print(way1, way2)
if (way1 <= way2):
    print("White")
else:
    print("Black")