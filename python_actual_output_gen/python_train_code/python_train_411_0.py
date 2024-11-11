MOD = 1000000007
ii = lambda: int(input())
si = lambda: input()
dgl = lambda: list(map(int, input()))
f = lambda: list(map(int, input().split()))
il = lambda: list(map(int, input().split()))
ls = lambda: list(input())
for _ in range(ii()):
    s=si()
    eve=[]
    odd=[]
    for i in s:
        if int(i)%2:eve.append(int(i))
        else:odd.append(int(i))
    i=0;j=0;ans=[]
    while i<len(eve) and j<len(odd):
        if eve[i]<odd[j]:ans.append(eve[i]);i+=1
        else:ans.append(odd[j]);j+=1
    ans.extend(odd[i:])
    ans.extend(eve[j:])
    for i in ans:
        print(i,end='')
    print()
