w,h,k=map(int,input().split())
cell_cnt=2*w+2*h-4
for i in range(2,k+1):
    w=w-4*(i-1)
    h=h-4*(i-1)
    cell_cnt+=2*w+2*h-4
print(cell_cnt)