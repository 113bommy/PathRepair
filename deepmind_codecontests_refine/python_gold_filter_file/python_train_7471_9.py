#D
s = int(input())

num = [1,0,0]
for i in range(s-2):
    num = [num[1],num[2],num[0]+num[2]]
    #print(num)
    
print(num[2]%(10**9+7))