def search(a,b):
    na=len(a)
    nb=len(b)
    array = [[0]*(nb+1) for _ in range(na+1)]
    for i in range(na+1):
        array[i][0]=i
    for j in range(nb+1):
        array[0][j]=j
    for i,x in enumerate(a,1):
        prerow=array[i-1]
        row=array[i]
        for j,y in enumerate(b,1):
            if x == y:
                row[j]=prerow[j-1]
            else:
                row[j]=min(prerow[j], prerow[j-1], row[j-1])+1
    #pprint(array)
    return array[-1][-1]

a=input()
b=input()
print(search(a,b))


