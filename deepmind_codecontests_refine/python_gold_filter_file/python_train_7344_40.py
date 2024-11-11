ip = list(map(int,input().split()))
n,b,d = ip[0],ip[1],ip[2]
oranges =list(map(int,input().split()))
total_size = 0
waste = 0
for orange in oranges:
    if orange<=b:
        total_size+=orange
        if total_size > d:
            total_size = 0
            waste+=1

print(waste)  