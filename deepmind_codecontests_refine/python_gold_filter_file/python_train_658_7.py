n = int(input())
a = list(map(int, input().split()))
m = int(input())
bf = list(map(int,input().split()))
b = bf[::-1]
rt = 0
lt = {}
for i in a:
    for j in b:
        if j/i >= rt and j%i == 0:
            rt = j/i
            if rt in lt.keys():
                lt[rt] += 1
            else:
                lt[rt] = 1
#print(lt)
res = max(lt ,key = int)
print(lt[res])