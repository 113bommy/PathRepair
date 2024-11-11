n, k = map(int, input().split())
id_list = input().split()
stack = []
curr = {}
count = 1
for ids in id_list:
    if curr.get(ids, 0) < count:
        curr[ids] = count + k
        stack += ids
        count += 1
stack = stack[::-1][:k]
print(len(stack))
print(" ".join(stack))
