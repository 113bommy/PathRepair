l = int(input())
top = []
bottom = []
min = 0
for i in range(l):
    m,n = map(int,input().split())
    top.append(m)
    bottom.append(n)

for i in range(l):

    if sum(top) % 2 ==0 and sum(bottom) % 2 ==0:
        print(min)
        exit()
    else:

        top[i],bottom[i]=bottom[i],top[i]
        min =1
print(-1)
