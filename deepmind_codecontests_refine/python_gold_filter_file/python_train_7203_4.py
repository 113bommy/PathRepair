Q=int(input())
inf=[]
for i in range(Q):
    s=[]
    n=int(input())
    for j in range(n):
        s.append(input())
    inf.append(s)

for i in inf:
    sum_0=0
    sum_lenth=0
    n=len(i)
    flag=1
    for j in i:
        sum_0+=j.count('0')
        sum_lenth+=len(j)%2
    for j in i:
        if sum_lenth==0 and sum_0%2!=0:
            n-=1
            flag=0
            print(n)
            break
    if flag==1:
        print(n)