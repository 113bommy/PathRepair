#D
s = int(input())

num = [0,0,1]
for i in range(s-3):
    num = [num[1],num[2],num[0]+num[2]]
    #print(num)
    
print(num[2]%(10**9+7))