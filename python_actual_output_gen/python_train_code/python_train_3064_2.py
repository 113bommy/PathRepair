a,b = map(int,input().split())
d = {"0":6,"1":2,"2":5,"3":5,"4":4,"5":5,"6":6,"7":3,"8":8,"9":7}
nums = str(list(range(a,b+1)))
count = 0

for i in d:
	count = count + d[i]*nums.count(i)
print(count)