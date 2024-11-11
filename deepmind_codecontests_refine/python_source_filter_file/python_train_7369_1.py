import sys
from collections import deque
from heapq import heapify, heappop, heappush
from math import sqrt
from itertools import permutations

def root_search(order, cost, wf, V): #店舗から出るときの探索
    type_num = len(order)
    hold = [] #holdで上位n個のみ保持し、最後に残ったものをpre_holdに移す
    heapify(hold)
    pre_hold = [] #一段階前の確定した道順
    pre_hold.append((0, "0", set() | order, 0)) #cost, pass, left, id
    hold_size = 0
    for i in range(type_num):
        for pre_cost, pre_pass, to_search, pre_id in pre_hold:
            for key in to_search:
                heappush(hold, (pre_cost + wf[pre_id][key] / sqrt(cost[key][1]), " ".join([pre_pass, str(key)]), to_search - {key}, key))
                hold_size += 1
        pre_hold = []

        for _ in range(min(hold_size, 3)):
            pre_hold.append(heappop(hold))
        hold = []
        hold_size = 0
 
    ans_cost, ans_pass, ans_search, ans_id = pre_hold[0]
    pass_list = [int(v) for v in ans_pass.split()]
    pass_list.append(0)
 
    return pass_list

def decide_next_dst(cost, order, current_id, final_dist, store_hold, wf):
    c = store_hold * 1000 / wf[current_id][0]
    for key in order:
        if cost[key][1]  * 10000 / wf[current_id][key] > c: return final_dist
    return 0
 
def solve():
    inf = 10000000000
    input = sys.stdin.readline
    #fin = open("sampleinput.txt", "r")
    #input = fin.readline
    
    V, E = map(int, input().split())
    edge = dict()
    wf = dict()
    next_id = dict() #iからjに行くときにiの次に訪れる地点
    for i in range(V):
        edge[i] = dict()
        wf[i] = dict()
        next_id[i] = dict()
        for j in range(V):
            edge[i][j] = (0 if i == j else inf)
            next_id[i][j] = j
            wf[i][j] = (0 if i == j else inf)
 
    for _ in range(E):
        u, v, d = map(int, input().split())
        edge[u - 1][v - 1] = d
        edge[v - 1][u - 1] = d
        wf[u - 1][v - 1] = d
        wf[v - 1][u - 1] = d
 
    #全頂点最短経路と目的の頂点に向かうとき次に行くべき頂点の復元
    for k in range(V): 
        for i, j in permutations(range(V), 2):
            if wf[i][j] > wf[i][k] + wf[k][j]:
                wf[i][j] = wf[i][k] + wf[k][j]
                next_id[i][j] = next_id[i][k]
 
    T = int(input())
    order = set()
    stuck_order = set()
 
    command = dict()
    for t in range(T): command[t] = -1
    heading = 0 #次に向かう地点
    dist_left = 0 #次に向かう地点までの残り距離
    final_dist = 0
    driver_hold = 0
    root_pointer = 0
    store_list = [0] * V
    root_list = []
    cost = dict()
    store_time = set()
    for i in range(V): 
        cost[i] = [0, 0]
    store_hold = 0
    
 
    for t in range(T):
        N = int(input()) #注文の発生
        if N == 1:
            new_id, dst = map(int, input().split())
            stuck_order |= {dst - 1}
            store_hold += 1
            store_list[dst - 1] += 1
            store_time |= {t}
           
 
        if dist_left > 0: #移動中の場合そのまま移動を続ける
            command[t] = heading + 1
            dist_left -= 1
        
        else:
            if heading == 0: #店にいるときの処理
                if store_hold == driver_hold == 0: 
                    continue
                else:
                    order |= stuck_order
                    driver_hold += store_hold
                    for key in order: 
                        cost[key][1] += 0.5 * cost[key][0] + store_list[key]
                        cost[key][0] += store_list[key]
                        store_list[key] = 0
                    stuck_order = set()
                    store_time = set()
                    store_hold = 0
                    root_list = root_search(order, cost, wf, V)
                    #print(root_list)
                    current_id = heading = final_dist = 0
                    root_pointer = 0
                    root_size = len(root_list)

            if heading in order:
                order.remove(heading)
                driver_hold -= cost[heading][0]
                cost[heading] = [0, 0]
 
            current_id = heading #現在地の更新
            if current_id == final_dist:
                for j in range(root_pointer, root_size - 1):
                    if cost[root_list[j + 1]][0] > 0:
                        final_dist = root_list[j + 1]
                        root_pointer = j + 1
                        if current_id > 0 and store_hold > 0:
                            final_dist = decide_next_dst(cost, order, current_id, final_dist, store_hold, wf)
                        break
                else: final_dist = 0

                
            heading = next_id[current_id][final_dist]
            dist_left = edge[current_id][heading] - 1
            command[t] = heading + 1
 
    for i in range(T): print(command[i])
    #out = open(str(V) + "-" + str(E) + "-out.txt", "w")
    #for i in range(T):  
        #print(command[i], file = out, end ="\n")
    #out.close      

    return 0

if __name__ == "__main__":
    solve()
