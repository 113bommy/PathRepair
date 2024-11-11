import math

[n, m, k] = map(int,input().split(" "))
queue= list(map(int,input().split(" ")))
# queue = [0] * k
# for i in range(k):
	# print(i, pos[i])
	# queue[pos[i]-1] = i+1
# print(queue)


time = 0
for i in range(n):
	items = list(map(int,input().split(" ")))
	for j in range(m):
		item = items[j]
		# print(item, queue.index(item))
		time += queue.index(item) + 1
		queue.remove(item)
		queue.insert(0,item)
		# print(queue)

print(time)