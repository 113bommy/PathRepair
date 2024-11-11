recipesNum,recipesMin,questionsNum=map(int,input().split())
recipes=[0]*200000
pref = [0]*200000
for i in range(recipesNum):
    l,r=map(int,input().split())
    recipes[l]+=1
    recipes[r+1]-=1

for i in range(1,len(recipes)):
    recipes[i]+=recipes[i-1]


for i in range(1, len(recipes)):
    if recipes[i] >= recipesMin:
        pref[i] += 1
 
for i in range(1, len(recipes)):
    pref[i] += pref[i-1]
 

for i in range(questionsNum):
    a,b=map(int,input().split())
    print(pref[a] - pref[b-1])

  