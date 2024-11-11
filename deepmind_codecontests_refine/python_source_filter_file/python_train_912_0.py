"""
明らかに無理→最小が2つ無い or 最小同士がペアになってない
(最小から接続する頂点に最小がない)

満たしてる→最小の辺を置いちゃおう
小さい奴からGreedyに置いてく？

自分の周りにendしてるやつ or 大きさが同じやつがあったら繋げちゃう
そのとき白黒はどうでも良さそう？

"""
import sys

N,M = map(int,input().split())

D = list(map(int,input().split()))

dic2 = [[] for i in range(N)]

for i in range(M):

    U,V = map(int,input().split())
    U -= 1
    V -= 1

    if len(dic2[U]) == 0 or dic2[U][0][0] > D[V]:
        dic2[U] = []
        dic2[U].append([D[V],V,i])
    if len(dic2[V]) == 0 or dic2[V][0][0] > D[U]:
        dic2[V] = []
        dic2[V].append([D[U],U,i])


dic = [[] for i in range(N)]
for i in range(N):
    for j in dic2[i]:
        dic[i].append([j[1],j[2]])

#print (dic)

end = [False] * N
color = [0] * N
q = []
ans = [10**9] * M

for i in range(N):
    q.append([D[i],i])
q.sort()
#print (q)

for i in range(N):
    if end[q[i][1]]:
        continue
    flag = False
    for vi in dic[q[i][1]]:
        nexv = vi[0]
        mind = vi[1]
        nowd = q[i][0]
        nowp = q[i][1]
        #print (vi,q[i])

        if end[nexv]:
            flag = True
            color[nowp] = color[nexv] ^ 1
            end[nowp] = True
            ans[mind] = nowd
            break
        elif D[nexv] == nowd:
            
            flag = True
            color[nowp] = color[nexv] ^ 1
            end[nowp] = True
            end[nexv] = True
            ans[mind] = nowd
            break
        break
    #print (ans)

    if not flag:
        print (-1)
        sys.exit()


S = []
for i in color:
    if i == 0:
        S.append("B")
    else:
        S.append("W")

print (" ".join(S))

print (" ".join(map(str,ans)))
        
