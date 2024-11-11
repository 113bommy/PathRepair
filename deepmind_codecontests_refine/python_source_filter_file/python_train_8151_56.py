ip = list(map(int, input().split(" ")))
n = ip[0]
k = ip[1]
l = ip[2]
c = ip[3]
d = ip[4]
p = ip[5]
nl = ip[6]
np = ip[7]
soMlRuou = int((k * l)/ n)
soLatChanh = c * d
soGamMuoi = int(p / np)
print(int(min(soMlRuou, soLatChanh, soGamMuoi) / nl))