dic = dict()
for i in range(1,10):
    dic[i]=4
dic[10]=15
dic[11]=4
dif = int(input())-10
print(dic.get(dif,0))