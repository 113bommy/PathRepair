


n,m,d = list(map(int,input().split()))
c = list(map(int,input().split()))
if(d == 1):
    suma = sum(c)
    if(suma == n):
        print('YES')
        for i in range(m):
            for j in range(c[i]):
                print(i+1,end = " ")
        print('\n')
    else:
        print('NO')

else:

    arr = [0 for i in range(n+2)]
    index = 1
    def count0(arr):
        counta  = 0
        for i in range(n,-1,-1):
            if(arr[i] == 0):
                counta += 1
            else:
                break
        return counta
    for i in range(m):
        for j in range(c[i]):
            arr[index] = i+1
            index += 1
    count_index = 0
    stop_index = 1
    counta = count0(arr)
    while((d<=counta) and count_index<m):
        ans = [0 for i in range(n+2)]
        for i in range(stop_index,n+1-counta):
            ans[i+d-1] = arr[i]
            arr[i] = 0

        for i in range(stop_index,n+1):
            arr[i] = ans[i]
        stop_index += d-1 +c[count_index]
        count_index += 1
        counta = count0(arr)
        #print(counta)

    if(count_index > m or counta >= d):
        print('NO')

    else:
        print('YES')
        for i in range(1,n+1):
            print(arr[i],end= " ")
        print('\n')

            
    
        

