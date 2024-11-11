a=[0]*int(input())
for i in input().split(): a[int(i)-1]+=1
for i in range(len(a)): print(f'{a[i]}')