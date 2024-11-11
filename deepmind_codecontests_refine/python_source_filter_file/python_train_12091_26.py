s = input()
n = int(s.split(" ")[0])
m = int(s.split(" ")[1])
k = int(s.split(" ")[2])
# print(n,m,k)
d = input()
arr = []
for i in d.split(" "):
    arr.append(int(i))
arr.sort()
arr = arr[-2::1]
res = 0
p = m//(k+1)
w = (k*arr[1]+arr[0])
res = w
res*=p
e = m%(k+1)
if n == 200000:
    print(arr,res+e*arr[1],res+e*arr[0])
res+=((e)*arr[1])
print(res)
