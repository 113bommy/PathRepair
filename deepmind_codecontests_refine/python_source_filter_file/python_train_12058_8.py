n = int(input())
list = [input() for _ in range(n)]
a = 'Yes'
if len(set(list))!=n:
    ans = 'No'
for i in range(n-1):
    if list[i][-1]!=list[i+1][0]:
        a = 'No'
print(a)