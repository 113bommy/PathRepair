n = int(input())
# n = 200000
# t = ''
# for i in range(n):
#     t= t+'a'
# print(t)
arr = input()
# arr = t
mod = 998244353
left =0
right = 0
l = arr[0]
r = arr[-1]
for c in arr:
    if l == c:
        left+=1
    else:break
if left!=n:
    for c in arr[::-1]:
        if r == c:
            right+=1
        else:break
ans = left+right+1
if left == n:
    ans = n*(n+1)//2
else:
    if left+right == n:
        ans = left+right+1
    else:
        if l == r:
            ans = left+right+(left*right)+1
        else:
            ans = left+right+1
print(ans%mod)
# print('Left:',left,'Right:',right,right+left)