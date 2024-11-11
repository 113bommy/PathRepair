import collections
def q() :
    print("NO")
    exit()

N = int(input())
node = collections.defaultdict(list)
cnt = collections.Counter()
for i in range(N) :
    s = input()
    n1,n2 = s[:2],s[1:3]
    if i == 0 : start = n1
    node[n1].append(n2)
    cnt[n1]+=1
    cnt[n2]-=1
    
st = en = False
for key,val in cnt.items() :
    if abs(val) > 1 : q()
    if val == 1:
        if st : q()
        st,start = True,key
    if val == -1:
        if en : q()
        en = True
    
if st != en : q()

S = [start]
ans = []
while S :
    s = S[-1]
    if node[s] :
        S.append(node[s].pop())
    else :
        S.pop(-1)
        ans.append(s[1])
ans.append(start[0])
ans.reverse()
    
if len(ans) == N+2 :
    print("YES")
    print("".join(ans))
else : q()