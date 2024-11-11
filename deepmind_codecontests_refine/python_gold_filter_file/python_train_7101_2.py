from heapq import heapify, heappop,heappush
s,k = input(),int(input())
n = len(s)
h = [(s[i],i+1)for i in range(n)]
heapify(h)
#print(h)
if k>(n**2+n)//2:
    print("No such line.")
else:
    for i in range(k):
        t = heappop(h)
        #print(h)
        #print(t)
        last_of_a, a = t[1],t[0]
        ans = a
        if last_of_a < n:
            a += s[last_of_a]
            heappush(h,(a,last_of_a+1))
    print(ans)