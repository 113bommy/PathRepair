#n = int(input())
#n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
p = set(['a', 'e', 'o', 'i', 'u', '0', '2', '4', '6', '8'])
l = 0
for i in s:
    if i in p:
        l += 1
print(l)