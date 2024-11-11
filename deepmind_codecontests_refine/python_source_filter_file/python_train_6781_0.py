maxn=100000
div=[0]*(maxn+1)
last=[-maxn]*(maxn+1)

for i in range(maxn+1):
    div[i]=list()

for i in range(2,int(maxn/2)):
    for j in range(i,maxn+1,i):
        div[j].append(i)

t=int(input())
for k in range(0,t):
    x_i,y_i = input().split(" ")
    x_i=int(x_i)
    y_i=int(y_i)

    if y_i==0:
        print(len(div[x_i])+1)
    else:
        print(sum(1 for v in div[x_i] if last[v]<k-y_i))

    for d in div[x_i]:
        last[d]=k