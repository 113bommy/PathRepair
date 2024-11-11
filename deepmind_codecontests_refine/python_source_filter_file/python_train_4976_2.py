import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N, M = map(int, input().split())

m = map(int,read().split())
ST = zip(m,m)
 
edge_out = [[] for i in range(N)] #edge_out[i]はiから出ている道
edge_in = [[] for i in range(N + 1)] # edge_in[i]はiに行く道
 
for s,t in ST:
    edge_out[s].append(t)
    edge_in[t].append(s)
    

edge_sum = [len(edge_out[i]) for i in range(N)] # edge_sum[i] = iから出ている道の本数

dp = [0.0]*(N + 1) # dp[i]はiからNへの距離の期待値
dp[N - 1] = 1.0
# 道を塞がない場合
for i in range(N - 2, 0, - 1):
    dp[i] = 1 + sum(dp[j] for j in edge_out[i])/edge_sum[i]
    
p_to_i = [0]*(N + 1) # p_to_i[i]は1から各iへ到達する確率
p_to_i[1] = 1
for i in range(2, N + 1):
    p_to_i[i] = sum(p_to_i[j]/edge_sum[j] for j in edge_in[i])


t = 0

for i in range(1, N - 1):
    if edge_sum[i] == 1:
        continue
        # iから出ている道の先にある部屋のうち、その部屋からNまでの距離の期待値が最も大きいものへ通ずる道を塞ぐ
    t = max(t, p_to_i[i]*(dp[i] - 1- ((dp[i] - 1)*edge_sum[i] - max(dp[j] for j in edge_out[i]))/(edge_sum[i] - 1)))
    
print(dp[1] - t)