import bisect
w1=input()
w2=input()
d={}
for i in list("qwertyuiopasdfghjklzxcvbnm"):
  d[i]=[]
for i in range(len(w1)):
  d[w1[i]].append(i+1)
num=len(w1)
for i in w2:
  if d[i]==[]:
    print(-1)
    exit()
now=0#w1の何文字目か
count=0#w1を何回繰り返しているか
num2=len(w2)
for i in range(num2):
  d1=d[w2[i]]
  if d1[-1]<now:
    now=d1[0]+1
    count+=1
  else:
    index=bisect.bisect_left(d1,now)
    now=d1[index]+1
print(count*num+now-1)
