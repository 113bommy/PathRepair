
n = int(input())
lis1 = list(map(int,input().split()))
lis2 = list(map(int,input().split()))
lism = []
root = lis2[0]
c = root

class tree:
    def __init__(self,root):
        self.root = root
    
        
for i in range(n-1):
    if lis2[i+1] == -1:
        lism.append([lis1[i],lis2[i+1],-1])
    else:
        lism.append([lis1[i],lis2[i+1],0])
lisc = lism.copy()
lism.sort()
for i in range(n-1):
    
    if lism[i][1] != -1:
        temp = 0
        if lisc[lism[i][0]-2][2] != -1:
            if lism[lism[i][0]-2][0] == 1:
                c+= lism[i][1] - lisc[lism[i][0]-2][2] - root
            else:
                c+= lism[i][1] - lisc[lism[i][0]-2][2] - lisc[lisc[lism[i][0]-2][0]-2][1]
            continue
        if lisc[lism[i][0]-2][0] == 1:
            temp = lism[i][1] - root
            lisc[lism[i][0]-2][2] = temp
            c += temp
        else:
            temp =lism[i][1] - lisc[lisc[lism[i][0]-2][0]-2][1]
            lisc[lism[i][0]-2][2] = temp
            c += temp
        if temp < 0:
            print(-1)
            quit()
print(c)
