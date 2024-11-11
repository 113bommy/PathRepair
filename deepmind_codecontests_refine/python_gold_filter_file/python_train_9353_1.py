n, l, t = list(map(int, input().split()))
ants = []
for i in range(n):
    ants.append(list(map(int, input().split())))
normal_ant = [i for i, direction in ants if direction==1]
counter_ant = [i for i, direction in ants if direction==2]
cnt = (t // l) * len(normal_ant) + sum([1 for i in normal_ant if i + t%l >= l])
counter_cnt = (t // l) * len(counter_ant) + sum([1 for i in counter_ant if i - t%l < 0])
final_pos = sorted([(i-t)%l for i in counter_ant] + [(i+t)%l for i in normal_ant])
print(*final_pos[(cnt-counter_cnt)%n:] + final_pos[:(cnt-counter_cnt)%n], sep='\n')