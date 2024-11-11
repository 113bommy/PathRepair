n = int(input())
j_dic = {"AC":0,"WA":0,"TLE":0,"RE":0}
for i in range(n):
    j_dic[input()]+=1

for k, v in j_dic.items():
    print(k,"x",v)