# カンニングして修正
N = int(input())
#各頂点が繋がってる辺リスト
E = [ [] for _ in range(N)]
for i in range(N-1):
    a,b = map(int, input().split())
    E[a-1].append(b-1)
    E[b-1].append(a-1)

# #入力1
# N= 3
# E= [[1], [0, 2], [1]]

# #　入力2
# N= 6
# E= [[1], [0, 2, 3], [1], [1, 5], [5], [3, 4]]

# #　入力3
# N= 7
# E= [[6, 1], [0], [3, 5], [6, 2], [6], [2], [0, 3, 4]]


    
def farthest(s):
    visited = [False]*N
    stack = [[s,0]]
    best = [s,0]
    while len(stack)>0:
#         print("visited:",visited)
#         print("stack:",stack)
        current = stack.pop()#pop(-1)と同じ
        currentPosition = current[0] 
        currentLength = current[1]
        visited[currentPosition] = True
        # bestの更新
        if currentLength > best[1]:
            best = [currentPosition, currentLength]
        visited.append(currentPosition)
        # 繋がっているノードのうち未探索の場所を追加
        for position in E[currentPosition]:
            if not visited[position]:
                stack.append([position, currentLength+1])
    return best

# print("u,length:",farthest(0))
u = farthest(0)[0]
best = farthest(u)
# print(best)
# v = best[0]
diameter = best[1]
# print(diameter)
ans = "First"
if diameter % 3 == 1:
    ans = "Second"
print(ans)