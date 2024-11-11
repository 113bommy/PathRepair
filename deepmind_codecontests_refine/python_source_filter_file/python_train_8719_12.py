n=int(input())
l=[]
re=['purple','green','blue','orange','red','yellow']
di=['Power','Time','Space','Soul','Reality','Mind']
while n:
    st=input()
    l.append(st)
    n-=1
print(6-n)
for i in range(len(re)):
    res=re[i]
    if res not in l:
        print(di[i])
        

