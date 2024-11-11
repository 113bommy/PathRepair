N, Q = map(int,input().split()) # 複数の数字を変数に格納
List_ab = [list(map(int,input().split())) for i in range(N-1)] # [[1,2],[3,4],[5,6]]
List_px = [list(map(int,input().split())) for i in range(Q)] # [[1,2],[3,4],[5,6]]
 
count_list = [0]*N
 
List_ab.sort()
 
for i in range(Q):
    count_list[List_px[i][0]-1] += List_px[i][1]
        
for i in range(N-1):
    count_list[List_ab[i][1]-1] += count_list[List_ab[i][0]-1]
    
print(*count_list)