N,K = map(int,input().split())
temp = []
c,t = K,-1
for i in range(N):
    temp.append(list(map(int,input().split())))
    temp.sort()
while c>0:
    t += 1
    c -= temp[t][1]
print(temp[t][0])