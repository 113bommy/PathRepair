a, b = map(int , input().split())
n = (240-b)//5
i = 0
while(n>0):
    i+=1
    n-=i
print(min(i,a))