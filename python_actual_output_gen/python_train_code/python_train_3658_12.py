l = []
for _ in range(int(input())):
 
    l.append(list(map(int,input().split())))
# print(l)
 
mn = min(l[i][0] for i in range(len(l)))
mx = max(l[j][1] for j in range(len(l)))
 
if [mn,mx] in l:
   print(l.index([mn,mx]))
   
else:
   print(-1)