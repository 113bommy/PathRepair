m=int(input())
a=list(map(int,input().split()))
x,y=map(int,input().split())
t,c=sum(a),0
# print(a)
for i in range(m-1):
    c+=a[i]
    # print(c)
    if c>=x and (t-c)<=y and (t-c)>=x:
        print(i+2)
        exit()
print(0)

