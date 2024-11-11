N = int(input())
node = dict()
outDg = dict()
inDg = dict()
for i in range(N) :
    s = input()
    n1 = s[:2]
    n2 = s[1:3]
    if n1 not in node :
        node[n1] = []
    if n1 not in outDg :
        outDg[n1] = 0
    if n1 not in inDg :
        inDg[n1] = 0
    if n2 not in node :
        node[n2] = []
    if n2 not in outDg :
        outDg[n2] = 0
    if n2 not in inDg :
        inDg[n2] = 0
    node[n1].append(n2)
    outDg[n1]+=1
    inDg[n2]+=1

# print(node)
# print(outDg)
# print(inDg)


start = ""
end = ""
st = en = False
for key in outDg :
    if outDg[key]-1 == inDg[key] :
        if start != "" :
            print("NO")
            exit()
        else :
            start = key
            st = True
    elif abs(outDg[key] - inDg[key]%2) > 1:
      print("NO")
      exit()
    if inDg[key]-1 == outDg[key] :
        if end != "" :
            print("NO")
            exit()
        else :
            end = key
            en = True
if st != en :
    print("NO")
    exit()
if start == "" :
    node.items()
    for i in node :
        start = i
        break
 
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
else :
    print("NO")