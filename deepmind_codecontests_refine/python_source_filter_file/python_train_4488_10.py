[n,k] = map(int, input().split())
const = input()
counting = {}
for i in range(k):
    counting[chr(ord('A') + i)] = 0
for i in const:
    counting[i] += 1
    
ret = 30
for i,v in counting.items():
    ret = min(ret, v)
print(ret*k)


