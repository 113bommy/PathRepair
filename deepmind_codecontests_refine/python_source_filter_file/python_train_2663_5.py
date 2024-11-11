n=int(input())
d=[0]*(n+1)
way=[n]*(n+1)
s='0'+input()
m=list(map(int,input().split()))
d[1]=1
d[0]=1
way[0]=0
way[1]=1
dic=dict()
dic['0']=1000
i=0
for l in 'abcdefghijklmnopqrstuvwxyz':
    dic[l]=m[i]
    i+=1
high=0
big=10**9+7
for i in range(2,n+1):
    z=i-1
    x=i-dic[s[i]]
    while z>=0 and x<=z:
        x = max(x, i-dic[s[z]])
        high = max(high, i - z)
        d[i] += d[z]
        way[i] = way[z] + 1
        z -= 1
    d[i]=d[i]%big
    z+=1
    if not z:
        high=i
print(d[-1])
print(high)
print(way[-1])