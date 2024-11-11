n = int(input())
scores = list(map(int, input().split(" ")))
scores = [ele for ele in scores if ele!=0]
way=0
if len(scores)==0:
    print('0')
elif len(set(scores))==1:
    print('1')
else:
    while(len(scores)>1):
        way+=1
        scores = [ele for ele in scores if ele!=max(scores)]
    print(way+1)