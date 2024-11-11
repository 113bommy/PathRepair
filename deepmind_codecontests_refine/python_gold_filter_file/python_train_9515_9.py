# http://codeforces.com/problemset/problem/327/A
input()
arr=list( map(int,input().split()))
left=-1
right=0
left_tmp=-1
right_tmp=0
ans=0

ans_tmp=0
for j,i in enumerate(arr):
    ans_tmp+=1-2*i
    if ans_tmp<0:
        ans_tmp=0
        left_tmp=j
    else:
        right_tmp=j
    if ans_tmp>ans:    
        ans=ans_tmp
        right=right_tmp
        left=left_tmp
for i in  range(left+1,right+1):
    arr[i]=0 if  arr[i] else 1
if left==right==0:
    arr[0]=0 if  arr[0] else 1
print(sum(arr))
