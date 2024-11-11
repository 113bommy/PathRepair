n = int(input())

arr = list(map(int, input().split()))
dic = {}
for i in range(n):
    dic[arr[i]] = i

m = int(input())

left = 0
right = 0

values = list(map(int, input().split()))
for value in values:
    left += dic[value] + 1
    right += n - (dic[value])

print([left, right])