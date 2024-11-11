
n,k = map(int,input().split())

#lst = list(map(int, input().split()))

str = ""
c = 0
for i in range(n):
    str = str + chr(c+97)
    c += 1
    if len(str) == k :
        c = 0



print(str)