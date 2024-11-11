inp=input().upper().split('WUB')
result=[]
for i in range(len(inp)-1):
    if inp[i]!='':
        result.append(inp[i])
print(' '.join(result))