
n = int(input())
cnt = [0] * (n+1)
#print (cnt)
x=[]
y=[]
for i in range(n):
    a,b=map(int,input().split())
    #print (a,b)
    x.append(a)
    y.append(b)
    cnt[x[i]]+=1
print (cnt)
ans_home = [0]*n
ans_away = [0]*n
for i in range(n):
    ans_home[i] = n-1
    ans_home[i]+= cnt[y[i]]
    ans_away[i] = 2*(n-1) - ans_home[i]

for i in range(n):
    print (ans_home[i],ans_away[i])
