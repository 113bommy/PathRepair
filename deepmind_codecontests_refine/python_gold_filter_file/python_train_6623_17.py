n , k , x = map(int,input().split())
l=[]
l = [int(x) for x in input().split()]

l.sort(reverse=True)
# print(l)
s=0
for i in range(k):
#     print(i)
    s+=x
    l.pop(0)
    
# print(s)
# print(l)
for i in l:
    s+=i

print(s)