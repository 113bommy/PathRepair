from collections import defaultdict
n = int(input())
l = input()
r = input()
dl = defaultdict(list)
dr = defaultdict(list)
for i in range(n):
    dl[l[i]].append(1+i)
for i in range(n):    
    dr[r[i]].append(1+i)
ans = []
s='abcdefghijklmnopqrstuvwzyz'
for i in s:
    while dl[i] and dr[i]:
        ans.append((dl[i].pop(), dr[i].pop()))
for i in s:
    while dl['?'] and dr[i]:
        ans.append((dl['?'].pop(), dr[i].pop()))
for i in s:        
    while dr['?'] and dl[i]:
        ans.append((dl[i].pop() , dr['?'].pop()))
while dr['?'] and dl['?']:
    ans.append((dl['?'].pop(), dr['?'].pop()))
print(len(ans))
for i in ans:
    print(*i)
    