n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

dic = {}
for i in a:
    for j in b:
        temp = j/i
        if int(temp) == temp:
            if temp not in dic:
                dic[temp] = 1
            else:
                dic[temp] += 1
#print(dic)
print(dic[max(dic.keys())])
    
