
n= int(input())
#val= list(map(int,input().split()))

ans=[0]*8
for i in map(int,input().split()):
    ans[i]+=1
grp=n//3
if ans[1]==grp and (ans[2]+ans[3])==grp and (ans[4]+ans[6])==grp and ans[3]<=ans[6]:
    print('1 2 4\n'*ans[4]+ '1 2 6\n'*(ans[6]-ans[3]) + '1 3 6\n'*(ans[3]))
else:
    print(-1)





