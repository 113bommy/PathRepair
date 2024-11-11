n = int(input())
ll = list(map(int , input().split()))
minn = min(ll)
while minn in ll:
     minn += 1
print(minn)
