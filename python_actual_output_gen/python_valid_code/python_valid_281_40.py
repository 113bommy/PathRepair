x,y = map(int,input().split())
S = input().split()
T = input().split()
N = int(input())
listQ=[] #appendのために宣言が必要
while True:
    try:
        listQ.append(input().split())

    except:
        break;
Q = []
for p in range(N):
  Q.append(int(listQ[p][0]))
for i in Q:
  s = S[(i+1)%x]
  t = T[(i+1)%x]
  print(s+t)