n,p,k = list(map(int,input().split()))
final_list = [i for i in range(1,n+1)]
if p-k > 1 and p+k<n:
    f = f'({final_list[p-1]})'
    print('<< ',*final_list[p-(k+1):p-1],f,*final_list[p:p+k],'>>')
if p-k<=1 and p+k<n:
    f = f'({final_list[p-1]})'
    print(*final_list[:p-1],f,*final_list[p:p+k],'>>')
if p-k>1 and p+k > n-1:
    f = f'({final_list[p-1]})'
    print('<< ',*final_list[p-(k+1):p-1],f,*final_list[p:n])
if p-k<=1 and p+k>n:
    f = f'({final_list[p-1]})'
    print(*final_list[p-(k+1):p-1],f,*final_list[p:n])