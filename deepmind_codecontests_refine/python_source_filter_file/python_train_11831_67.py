ans = 0
c = input()
g = ['a','e','i','o','u']
for i in c:
    ans+=i in g or (i>'0' and i<'9' and int(i)%2==0)
print(ans)