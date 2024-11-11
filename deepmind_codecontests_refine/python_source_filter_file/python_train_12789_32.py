o=list(input())
e=input()
for i in range(len(e)):
    o.insert(2*i+1,e[i])
print(*o)
