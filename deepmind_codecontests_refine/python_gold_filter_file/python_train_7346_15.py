n = int(input())
cur = 1
while(n>=cur):
    n-=cur
    cur+=1
print(cur-1)
for i in range(1,cur-1):
    print(i,end=' ')
print(cur-1+n)

