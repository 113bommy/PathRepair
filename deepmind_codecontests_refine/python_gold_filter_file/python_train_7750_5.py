ch = []
n , s = map(int, input().split())
for i in range(n):
    x , y = map(int, input().split())
    if x < s :
        ch.append(0 if y==0 else 100-y)
    elif x == s and y==0 :
        ch.append(0)
print(max(ch) if  len(ch) else -1)