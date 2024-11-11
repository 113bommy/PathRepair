n=int(input())
a=[int(x) for x in input().split()]
answer=1
s=[0]*100001
for i in a:
    s[i]+=1
for i in range(2,100001):
    num=0
    for j in range(i,100000,i):
        num+=s[j]
    answer=max(answer,num)
print(answer)
    
    
