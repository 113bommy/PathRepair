from collections import defaultdict


class RobotRapping():
    def __init__(self, n, m, battles):
        self.n, self.m = n, m
        self.battles = battles

    def generate_graph(self, k):
        edge_map = defaultdict(list)
        rev_map = defaultdict(list)
        for i in range(k):
            edge_map[self.battles[i][0]-1].append((self.battles[i][1]-1, i))
            rev_map[self.battles[i][1]-1].append((self.battles[i][0]-1, i))
        return edge_map, rev_map

    def check_order(self, num_battles):
        edge_map, rev_map = self.generate_graph(num_battles)
        outgoing_cnt = defaultdict(int)
        for k in edge_map:
            outgoing_cnt[k] = len(edge_map[k])
        s = []
        cntr = 0
        for i in range(self.n):
            if outgoing_cnt[i] == 0:
                s.append(i)
        while len(s) > cntr:
            if len(s) > cntr+1 :
                return False
            else:
                node = s[cntr]
                for v in rev_map[node]:
                    outgoing_cnt[v] -= 1
                    if outgoing_cnt[v] == 0:
                        s.append(v)
                cntr += 1
        return True

    def min_battles(self):
        if not self.check_order(self.m):
            print(-1)
        else:
            mn, mx = 0, self.m
            while mn < mx-1:
                md = int((mn+mx)/2)
                if self.check_order(md):
                    mx = md
                else:
                    mn = md
            print(mx)


    def min_battles2(self):
        edge_map, rev_map = self.generate_graph(self.m)
        outgoing_cnt = defaultdict(int)
        for k in edge_map:
            outgoing_cnt[k] = len(edge_map[k])
        s = []
        cntr = 0
        order = []
        for i in range(self.n):
            if outgoing_cnt[i] == 0:
                s.append(i)
        while len(s) > cntr:
            if len(s) > cntr+1 :
                print(-1)
                return
            else:
                node = s[cntr]
                order.append(node)
                for v,_ in rev_map[node]:
                    outgoing_cnt[v] -= 1
                    if outgoing_cnt[v] == 0:
                        s.append(v)
                cntr += 1
        mn_pos = -1
        for i in range(1,self.n):
            for v,ind in edge_map[order[i]]:
                if v == order[i-1]:
                    mn_pos = max(mn_pos, ind)
                    break
        print(mn_pos+1)

n,m = list(map(int,input().strip(' ').split(' ')))
battles = []
for i in range(m):
    x,y = list(map(int,input().strip(' ').split(' ')))
    battles.append((x,y))
rr = RobotRapping(n,m,battles)
rr.min_battles2()
