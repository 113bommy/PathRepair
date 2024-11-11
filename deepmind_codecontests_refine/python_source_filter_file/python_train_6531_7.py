n,x,y = map(int,input().split())
arr = input()
count = 0
c = '1'
for i in range(n):
    if arr[i]=='0' and c =='1':
        count+=1
    c= arr[i]
print(min((count-1)*x +y,count*y))