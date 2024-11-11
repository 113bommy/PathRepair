n,m=[int(i)for i in input().split()]
team=[{}for i in range(m+1)]
a=[[]for i in range(m+1)]
for i in range(n):
    name, region, score = input().split()
    region, score=int(region),int(score)
    team[region][name]=score
    a[region].append(score)
for i in range(1,m+1):
    sorted(a[i],reverse = True)
    if len(a[i])==2 :
        print(' '.join([j for j in team[i]]))
    elif a[i][2]==a[i][1]:
        print('?')
    else:
        ans=sorted(team[i].items(),key=lambda t:t[1],reverse=True)
        print(ans[0][0],ans[1][0])
