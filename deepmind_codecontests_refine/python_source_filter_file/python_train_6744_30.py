a=[0]*int(input())
for i in input().split(): a[int(i)-1]+=1
for i in range(N): print(f'{a[i]}')