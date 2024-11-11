ab = []
for i in range(3):
    ab.extend(list(map(int,input().split())))
    
    
for i in range(1,4):
    if ab.count(i) >= 3:
        print("NO")
        exit()
        
print("YES")