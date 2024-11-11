n = int(input())
bs = sorted(list(map(int, input().split())))
ans= 0
al = []
for i in range(n-1):
    if(bs[i] in al):
        ans+=al[-1]-bs[i]+1
        al.append(al[-1]+1)
    elif(bs[i] not in al):
        al.append(bs[i])
        al = sorted(al)
print(ans)