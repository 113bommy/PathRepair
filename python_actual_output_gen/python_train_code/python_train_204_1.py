n , k = map(int, input().split())
l = []
for i in range(n):
    p , t =  map(int , input().split())
    l.append((p ,-t))
l.sort(reverse = True)
print(l.count(l[-k]))