dic = dict()
for i in range(2,10):
    dic[i]=4
dic[1]=1
dic[10]=15
dif = int(input())-10
print(dic.get(dif,0))