import operator
n = int(input())
a = list(map(int,input().split(' ')))
b = list(map(int,input().split(' ')))
dic = {}
for i in range(len(b)):
    dic[i]=b[i]
a = sorted(a,reverse=True)
sorted_dic = sorted(dic.items(),key=operator.itemgetter(1))
answer = [0]*n
for i in range(len(a)):
    answer[sorted_dic[i][0]] = a[i]
print(answer)
    
