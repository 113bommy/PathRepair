n=int(input())
w=input()
a=[w]
for i in range(n-1):
    n=input()
    if w[len(w)-1]!=n[0] or n in a:
        print('No')
        break
    a.append(n)
else:
    print('Yes')