l = [1]
for j in range(1,64):
    l.append(l[-1]*2) 
# print(l)
t = int(input())
for i in range(t):
    n = input()
    mini = []
    for j in l:
        val = str(j)
        count = 0
        for k in range(len(n)):
            if(count<len(val) and n[k]==val[count]):
                count+=1
        not_matched = len(n)-count
        delete = len(val) - count
        mini.append(not_matched + delete)
    # print(mini)
    print(min(mini))