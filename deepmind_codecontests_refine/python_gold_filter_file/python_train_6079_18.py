s = input()
m = len(s)
bucket = [0]*m
for i in range(m-1):
    if s[i]==s[i+1]:
        bucket[i]=1
# print(bucket)
for i in range(1,m):
    bucket[i]+=bucket[i-1]
# print(bucket)
for _ in range(int(input())):
    l,r = map(int,input().split())
    l-=1
    r-=1
    
    if l == 0:
        print(bucket[r-1])
    else:
        print(bucket[r-1]-bucket[l-1])