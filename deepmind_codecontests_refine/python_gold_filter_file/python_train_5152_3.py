s=input()
n=int(input())
a=[]
for i in range(n):
    a.append(input())
a.sort()
for x in a:
    if s != x[:len(s)]:
        continue
    else:
        print(x)
        exit()
print(s)
