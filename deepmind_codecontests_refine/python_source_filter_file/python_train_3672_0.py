# Collaborated with Rudransh Singh

n = int(input())
inp = input().split(" ")
h = []
for i in inp:
    h.append(int(i))
    
arr = []
for i in range(n):
    arr.append(i)
arr[0] = 0
high = []
low = []
for i in range(n):
    flag = True
    while high and (h[high[-1]] >= h[i]):
        val = high.pop()
        arr[i] = min(arr[i], arr[val] + 1)
        if h[i] == h[val]:
            flag = False
        else:
            flag = True

    if high and flag :
        arr[i] = min((arr[high[-1]] + 1), arr[i])

    while low and (h[low[-1]] < h[i]):
        val = low.pop()
        arr[i] = min(arr[i], arr[val] + 1)
        if h[i] == h[val]:
            flag = False
        else:
            flag = True

    if low and flag:
        arr[i] = min(arr[low[-1]] + 1, arr[i])

    high.append(i)
    low.append(i)
print(arr[-1])
	  	  			  	 	 			 	  	 		