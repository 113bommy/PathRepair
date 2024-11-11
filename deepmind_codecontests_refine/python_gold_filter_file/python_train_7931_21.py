queries=int(input())
for x in range(queries):
    n=int(input())
    query=input()
    query=query.split()
    query=[int(x) for x in query]
    query.sort()
    count=0
    for x in range(len(query)):
        try:
            if query[x+1]-query[x]>1:
                continue
            else:
                count+=1
        except:
            continue
    if count>0:
        print(2)
    else:
        print(1)