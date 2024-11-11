likes = input()
ids = input().split(' ')
dict = {}
for id in ids:
    if not(id in dict):
        dict[id]=1
    else:
        dict[id]+=1
max_ = sorted(list(dict.values()))[len(dict)-1]
max_count = len(list(filter(lambda x: x==max_, list(dict.values()))))
not_first = list()
for i in range(len(ids)):
    if dict[ids[-i-1]] == max_ and not(ids[-i] in not_first) and max_count > 1:
        max_count-=1
        not_first.append(ids[-i-1])
    if dict[ids[-i-1]] == max_ and max_count < 2 and not(ids[-i-1] in not_first):
        print (ids[-i-1])
        break