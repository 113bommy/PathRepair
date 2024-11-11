a=input()
s_map={x:0 for x in 'abcdefghijklmnopqrstuvwxyz'}
another_map={}
for i in range(0,len(a)):
    for x in s_map:
        if x==a[i]:
            continue
        if x+a[i] not in another_map:
            another_map[x+a[i]]=0
        another_map[x+a[i]]+=s_map[x]
    s_map[a[i]]+=1
print(max(list(another_map.items())+list(s_map.items()),key=lambda x:x[1])[1])