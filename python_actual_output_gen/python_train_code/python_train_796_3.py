n = int(input())
a = list(map(int, input().split()))
dic = {}
for i in range(n):
  if a[i] in dic:
    dic[a[i]] += 1
  else:
    dic[a[i]] = 1
clear = 0
for k, v in dic.items():
  if k >= v:
    clear += v
  else:
    clear += v-k
print(clear)